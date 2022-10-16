#include<bits/stdc++.h>
#define MAXN   111
#define MAXS   110110
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
double f[MAXN][MAXS],s[MAXN][MAXS];
int x[MAXN];
int n,m,sum;
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&x[i]);
    if (m==1) {
        printf("%.15lf\n",1.0);
        exit(0);
    }
    FOR(i,1,n) sum+=x[i];
}
void optimize(void) {
    f[0][0]=1.0;
    REP(i,MAXS) s[0][i]=1.0;
    FOR(i,1,n) REP(j,MAXS) {
        if (j>0) f[i][j]+=s[i-1][j-1]/(m-1);
        if (j>m) f[i][j]-=s[i-1][j-m-1]/(m-1);
        if (j>=x[i]) f[i][j]-=f[i-1][j-x[i]]/(m-1);
        s[i][j]=j==0?f[i][j]:s[i][j-1]+f[i][j];
    }
    printf("%.15lf\n",s[n][sum-1]*(m-1)+1.0);
}
int main(void) {
    init();
    optimize();
    return 0;
}