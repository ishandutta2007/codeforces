#include<bits/stdc++.h>
#define MAX   505
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int mod=(int)1e9+7;
int f[MAX][MAX];
int a[MAX];
int n;
void init(void) {
    scanf("%d",&n);
    FOR(i,1,n) scanf("%d",&a[i]);
}
int dp(int l,int r) {
    if (l>=r) return (1);
    int &res=f[l][r];
    if (res>=0) return (res);
    res=dp(l+1,r);
    FOR(i,l+1,r-1) if (a[l+1]<a[i+1]) res=(res+1LL*dp(l+1,i)*dp(i,r))%mod;
    return (res);
}
void process(void) {
    memset(f,-1,sizeof f);
    printf("%d\n",dp(1,n));
}
int main(void) {
    init();
    process();
    return 0;
}