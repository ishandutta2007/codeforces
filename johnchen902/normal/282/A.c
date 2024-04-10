#include <stdio.h>
int main(){
    int i, x = 0;
    char string[4];
    scanf("%d\n", &i);
    for(; i > 0; i--)
        gets(string)[1] == '+' ? x++ : x--;
    printf("%d\n", x);
    return 0;
}