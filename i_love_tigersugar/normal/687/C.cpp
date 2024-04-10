#include<bits/stdc++.h>
#define MAX   515
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
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
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }
int n,m,a[MAX];
bool dp[MAX][MAX][MAX];
void init(void) {
    scanf("%d%d",&n,&m);
    FOR(i,1,n) scanf("%d",&a[i]);
}
void process(void) {
    dp[0][0][0]=true;
    REP(i,n) REP(j,m+1) REP(k,m+1) if (dp[i][j][k])
        REP(x,2) REP(y,x+1) if (j+x*a[i+1]<=m)
            dp[i+1][j+x*a[i+1]][k+y*a[i+1]]=true;
    vector<int> res;
    REP(i,m+1) if (dp[n][m][i]) res.push_back(i);
    printf("%d\n",(int)res.size());
    FORE(it,res) printf("%d ",*it); printf("\n");
}
int main(void) {
    init();
    process();
    return 0;
}