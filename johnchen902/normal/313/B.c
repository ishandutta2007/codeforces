#include <stdio.h>
#include <string.h>

char s[100001];
int a[100000];

int main(){
    scanf("%s", s);
    int len = strlen(s), i = 1;
    a[0] = 0;
    for(; i < len; i++)
        a[i] += a[i-1] + ( s[i] == s[i-1] );
    int m;
    for(scanf("%d", &m); m > 0; m--){
        int l, r;
        scanf("%d%d", &l, &r);
        printf("%d\n", a[r - 1] - a[l - 1]);
    }
    // system("pause");
    return 0;
}