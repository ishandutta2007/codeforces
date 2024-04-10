#include<bits/stdc++.h>
#define MAX   200200
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define fi   first
#define se   second
using namespace std;
const int mod=(int)1e9+7;
pair<int,int> cell[MAX];
int n,maxR,maxC;
int f[MAX][2];
int frac[MAX],finv[MAX];
int inverse(int x) {
    int res=1;
    int mul=x;
    int k=mod-2;
    while (k>0) {
        if (k&1) res=1LL*res*mul%mod;
        mul=1LL*mul*mul%mod;
        k>>=1;
    }
    return (res);
}
void init(void) {
    scanf("%d%d%d",&maxR,&maxC,&n);
    FOR(i,1,n) scanf("%d%d",&cell[i].fi,&cell[i].se);
    sort(cell+1,cell+n+1);
    frac[0]=finv[0]=1;
    FOR(i,1,MAX-1) {
        frac[i]=1LL*frac[i-1]*i%mod;
        finv[i]=inverse(frac[i]);
    }
}
int comb(int k,int n) {
    if (k>n) return (0);
    return (1LL*frac[n]*finv[k]%mod*finv[n-k]%mod);
}
int countWay(int x1,int y1,int x2,int y2) {
    return (comb(x2-x1,x2-x1+y2-y1));
}
void process(void) {
    FOR(i,1,n) f[i][1]=countWay(1,1,cell[i].fi,cell[i].se);
    FOR(i,1,n) FOR(j,i+1,n) if (cell[i].fi<=cell[j].fi && cell[i].se<=cell[j].se)
        REP(k,2) f[j][k^1]=(f[j][k^1]+1LL*f[i][k]*countWay(cell[i].fi,cell[i].se,cell[j].fi,cell[j].se))%mod;
    int res=countWay(1,1,maxR,maxC);
    FOR(i,1,n) {
        res=(res-1LL*f[i][1]*countWay(cell[i].fi,cell[i].se,maxR,maxC)%mod+mod)%mod;
        res=(res+1LL*f[i][0]*countWay(cell[i].fi,cell[i].se,maxR,maxC)%mod+mod)%mod;
    }
    printf("%d\n",res);
}
int main(void) {
    init();
    process();
    return 0;
}