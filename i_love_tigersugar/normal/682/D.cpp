#include<bits/stdc++.h>
#define MAX   1212
#define MAXP   12
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
char s[MAX],t[MAX];
int m,n,p,f[MAX][MAX][MAXP][2];
void init(void) {
    scanf("%d%d%d",&m,&n,&p);
    scanf("%s",s+1);
    scanf("%s",t+1);
}
void process(void) {
    memset(f,-0x3f,sizeof f);
    f[0][0][0][0]=0;
    REP(i,m+1) REP(j,n+1) REP(k,p+1) REP(l,2) if (f[i][j][k][l]>=0) {
        if (i<m) maximize(f[i+1][j][k][0],f[i][j][k][l]);
        if (j<n) maximize(f[i][j+1][k][0],f[i][j][k][l]);
        if (i<m && j<n && s[i+1]==t[j+1]) {
            if (l) maximize(f[i+1][j+1][k][l],f[i][j][k][l]+1);
            if (k<p) maximize(f[i+1][j+1][k+1][1],f[i][j][k][l]+1);
        }
    }
    printf("%d\n",max(f[m][n][p][0],f[m][n][p][1]));
}
int main(void) {
    init();
    process();
    return 0;
}