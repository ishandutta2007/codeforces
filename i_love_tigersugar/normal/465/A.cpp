#include<cstdio>
#define MAX   111
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
char s[MAX];
int n;
int main(void) {
    scanf("%d",&n);
    scanf("%s",s);
    int cnt=0;
    REP(i,n) if (s[i]=='1') cnt++; else break;
    printf("%d",cnt<n?cnt+1:n);
    return 0;
}