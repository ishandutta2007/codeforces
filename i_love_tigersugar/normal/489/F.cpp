#include<bits/stdc++.h>
#define MAX   505
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
typedef long long ll;
const ll INF=(ll)1e18+7LL;
const int LIM=(int)1e9+7;
int n,m,mod;
char a[MAX][MAX];
int prod[MAX][MAX];
int comb[MAX];
ll f[2][MAX][MAX];
void add(ll &a,ll b) {
    a+=b;
    if (a>INF) a%=mod;
}
void init(void) {
    scanf("%d%d%d",&n,&m,&mod);
    REP(i,m) scanf("%s",a[i]+1);
    REP(i,MAX) REP(j,MAX) prod[i][j]=1LL*i*j%mod;
    REP(i,MAX) if (i>=2) comb[i]=1LL*i*(i-1)/2%mod;
}
void optimize(void) {
    f[(n+1)&1][0][0]=1;
    FORD(i,n,m+1) {
        int cur=i&1;
        int next=cur^1;
        memset(f[cur],0,sizeof f[cur]);
        FOR(c0,0,n) FOR(c1,0,n-c0) {
            if (c0>=2) add(f[cur][c0][c1],1LL*comb[c0]*f[next][c0-2][c1+2]);
            if (c0>=1 && c1>=1) add(f[cur][c0][c1],1LL*prod[c0][c1]*f[next][c0-1][c1]);
            if (c1>=2) add(f[cur][c0][c1],1LL*comb[c1]*f[next][c0][c1-2]);
            if (f[cur][c0][c1]>LIM) f[cur][c0][c1]%=mod;
        }
    }
    int c[2];
    REP(i,2) c[i]=0;
    FOR(i,1,n) {
        int cnt=0;
        REP(j,m) if (a[j][i]=='1') cnt++;
        assert(0<=cnt && cnt<=2);
        if (cnt<2) c[cnt]++;
    }
    printf("%d",(int)f[(m+1)&1][c[0]][c[1]]%mod);
}
int main(void) {
    init();
    optimize();
    return 0;
}