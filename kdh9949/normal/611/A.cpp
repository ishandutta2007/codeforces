#include <cstdio>

int n;
char str[10];

int main(){
    scanf("%d of %s", &n, str);
    if(str[0] == 'w'){
        if(n == 5 || n == 6) puts("53");
        else puts("52");
    }
    else{
        if(n == 30) puts("11");
        else if(n == 31) puts("7");
        else puts("12");
    }
}