#include <stdio.h>
#include <stdint.h>

// 4바이트 정수를 처리하기 위해서 uint32_t 형식을 사용
// 파일에서 숫자을 읽기 위해서는 fopen, fread 함수를 사용
//uint32_t aaa = 123123123;

int main(int argc, char* argv[])
{
    char buf1[4 ] = { 0, };    // 파일을 읽을 때 사용할 임시 공간, 미리 0으로 전부 초기화
    char buf2[4 ] = { 0, };
    char buf3[4 ] = { 0, };
    char buf4[4 ] = { 0, };
    char buf[4 ] = { 0, };
    uint32_t result;

    FILE *fp1 = fopen(argv[1], "r");     
    fread(buf1, 4, 1, fp1);  
    //printf("%u\n", *(uint32_t *)buf1);

    buf2[0] = buf1[3];
    buf2[1] = buf1[2];
    buf2[2] = buf1[1];
    buf2[3] = buf1[0];

    printf("%u(0x%x) + ", *(uint32_t *)buf2,*(uint32_t *)buf2);


    FILE *fp2 = fopen(argv[2], "r");     
    fread(buf3, 4, 1, fp2);  

    buf4[0] = buf3[3];
    buf4[1] = buf3[2];
    buf4[2] = buf3[1];
    buf4[3] = buf3[0];

    printf("%u(0x%x) + ", *(uint32_t *)buf4,*(uint32_t *)buf4);

    result = *(uint32_t *)buf4 + *(uint32_t *)buf2;
    
    printf("%d(0x%x)\n\n",result,result);
    
    fclose(fp1);    // 파일 포인터 닫기
    fclose(fp2);  
    return 0;
}



