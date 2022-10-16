#include<bits/stdc++.h>
#define MAX   1000100
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
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
const long long INF=(long long)1e18+7LL;
int a[MAX],n,remCost,changeCost;
long long f[MAX][3][2];
void init(void) {
    scanf("%d%d%d",&n,&remCost,&changeCost);
    FOR(i,1,n) scanf("%d",&a[i]);
}
vector<int> primeFact(int x) {
    vector<int> res;
    for (int i=2;1LL*i*i<=x;i=i+1) if (x%i==0) {
        res.push_back(i);
        while (x%i==0) x/=i;
    }
    if (x>1) res.push_back(x);
    return (res);
}
long long getCost(int prime) {
    memset(f,0x3f,sizeof f);
    f[0][0][0]=0;
    REP(i,n) REP(j,3) REP(k,2) if (f[i][j][k]<INF) {
        if (j!=2) minimize(f[i+1][1][k],f[i][j][k]+remCost);
        FOR(t,a[i+1]-1,a[i+1]+1) if (t%prime==0)
            minimize(f[i+1][j==0?0:2][true],f[i][j][k]+(t==a[i+1]?0:changeCost));
    }
    long long res=INF;
    REP(i,3) minimize(res,f[n][i][true]);
    return (res);
}
void process(void) {
    long long res=INF;
    FOR(t,-1,1) {
        vector<int> f1=primeFact(a[1]+t);
        vector<int> fn=primeFact(a[n]+t);
        FORE(it,f1) minimize(res,getCost(*it));
        FORE(it,fn) minimize(res,getCost(*it));
    }
    cout<<res<<endl;
}
int main(void) {
    init();
    process();
    return 0;
}