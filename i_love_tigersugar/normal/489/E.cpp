#include<bits/stdc++.h>
#define MAX   1111
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
using namespace std;
const double INF=1e7;
int d[MAX],b[MAX];
double cost[MAX][MAX];
double f[MAX];
int trace[MAX];
int n,len;
inline double Abs(double x) {
    return (x<0?-x:x);
}
void init(void) {
    scanf("%d%d",&n,&len);
    FOR(i,1,n) scanf("%d%d",&d[i],&b[i]);
    FOR(i,1,n) FOR(j,i+1,n) cost[i][j]=sqrt(Abs(d[j]-d[i]-len));
}
bool ok(double x) {
    FOR(i,1,n) {
        f[i]=sqrt(Abs(d[i]-len))-x*b[i];
        trace[i]=0;
        FOR(j,1,i-1) if (f[j]+cost[j][i]-x*b[i]<f[i]) {
            f[i]=f[j]+cost[j][i]-x*b[i];
            trace[i]=j;
        }
    }
    return (f[n]<0);
}
void findWay(double x) {
    ok(x);
    int u=n;
    vector<int> v;
    while (u>0) {
        v.push_back(u);
        u=trace[u];
    }
    reverse(v.begin(),v.end());
    FORE(it,v) printf("%d ",*it);
}
void process(void) {
    double L=0;
    double R=INF;
    REP(zz,55) {
        double M=(L+R)/2;
        if (ok(M)) R=M; else L=M;
    }
    findWay((L+R)/2);
}
int main(void) {
    init();
    process();
    return 0;
}