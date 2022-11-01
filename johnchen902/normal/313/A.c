#include <stdio.h>

int main(){
    int a;
    scanf("%d", &a);
    if(a > 0)
        printf("%d\n", a);
    else{
        int b = a / 10, c = a / 100 * 10 + a % 10;
        printf("%d\n", b > c ? b : c);
    }
    //system("pause");
    return 0;
}