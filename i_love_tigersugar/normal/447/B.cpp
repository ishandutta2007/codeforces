#include<bits/stdc++.h>
#define MAX   1111
#define REP(i,n) for (int i=0;i<(n);i=i+1)
char s[MAX];
int n,k,res,a[MAX];
int main(void) {
    scanf("%s",s);
    n=strlen(s);
    scanf("%d",&k);
    REP(i,26) scanf("%d",&a[i]);
    REP(i,n) res+=a[s[i]-'a']*(i+1);
    int t=-1;
    REP(i,26) if (a[i]>t) t=a[i];
    REP(i,k) res+=t*(i+n+1);
    printf("%d",res);
    return 0;
}