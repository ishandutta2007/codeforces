#include<bits/stdc++.h>
#define MAX   200200
#define MAXM   55
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int a[MAX],n,m;
double f[MAX][MAXM];
double totCost[MAX],sum[MAX],sumInv[MAX];
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
    FOR(i,1,n) sum[i]=sum[i-1]+a[i];
    FOR(i,1,n) sumInv[i]=sumInv[i-1]+1.0/a[i];
    FOR(i,1,n) totCost[i]=totCost[i-1]+1.0/a[i]*sum[i];
}
double getCost(int l,int r) {
    return (totCost[r]-totCost[l-1]-sum[l-1]*(sumInv[r]-sumInv[l-1]));
}
void calcDP(int l,int r,int xl,int xr,int j) {
    if (l>r) return;
    int m=(l+r)>>1;
    f[m][j]=-1.0;
    int best=-1;
    FOR(i,max(xl,j-1),min(xr,m-1)) if (f[m][j]<-0.5 || f[m][j]>f[i][j-1]+getCost(i+1,m)) {
        f[m][j]=f[i][j-1]+getCost(i+1,m);
        best=i;
    }
    calcDP(l,m-1,xl,best,j);
    calcDP(m+1,r,best,xr,j);
}
void process(void) {
    FOR(i,1,n) f[i][1]=totCost[i];
    FOR(j,2,m) calcDP(j,n,1,n,j);
    printf("%.11lf\n",f[n][m]);
}
int main(void) {
    init();
    process();
    return 0;
}