#include<bits/stdc++.h>
#define MAX   1000100
typedef long long ll;
ll n,m,ls,g;
char x[MAX];
char y[MAX];
int cx[MAX][27];
int cy[MAX][27];
int lx,ly;
int gcd(int a,int b) {
    while (true) {
        if (a==0) return (b);
        if (b==0) return (a);
        if (a%b==0) return (b);
        if (b%a==0) return (a);
        if (a>b) a=a%b; else b=b%a;
    }
}
ll lcm(const int &a,const int &b) {
    return (1LL*a*b/gcd(a,b));
}
void init(void) {
    scanf("%I64d",&m);
    scanf("%I64d",&n);
    scanf("%s",x);
    scanf("%s",y);
    lx=strlen(x);
    ly=strlen(y);
    ls=m*lx;
}
void count(void) {
    g=gcd(lx,ly);
    int i,j;
    for (i=0;i<lx;i=i+1)
        cx[i%g][x[i]-'a']++;
    for (i=0;i<ly;i=i+1)
        cy[i%g][y[i]-'a']++;
    ll cnt=0LL;
    for (i=0;i<g;i=i+1)
        for (j='a';j<='z';j=j+1)
            cnt=cnt+1LL*cx[i][j-'a']*cy[i][j-'a'];
    ll cyc=lcm(lx,ly);
    printf("%I64d",(ls/cyc)*(cyc-cnt));
}
int main(void) {
    init();
    count();
    return 0;
}