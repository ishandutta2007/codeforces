#include <cstdio>

int main(){
    int n;
    scanf("%d", &n);
    if(n % 2) puts("0");
    else printf("%d", (n / 4) - (n % 4 == 0));
}