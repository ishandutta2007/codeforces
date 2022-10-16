#include<bits/stdc++.h>
#define MAX   227
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
int res[MAX][MAX],m,n,q;
void solve(bool yes) {
    if (yes) {
        FOR(i,1,m) {
            FOR(j,1,n) printf("%d ",res[i][j]);
            printf("\n");
        }
    } else printf("-1\n");
    exit(0);
}
void oddCol(void) {
    int tmp=0;
    FOR(i,1,m) FOR(j,1,n) if (tmp<q) res[i][j]=++tmp;
    solve(tmp>=q);
}
void oddRow(void) {
    int tmp=0;
    FOR(j,1,n) FOR(i,1,m) if (tmp<q) res[i][j]=++tmp;
    solve(tmp>=q);
}
void bothEven(void) {
    int capa=m*n/2;
    int numEven=q/2;
    int numOdd=q-numEven;
    if (numEven>capa || numOdd>capa) solve(false);
    int tmp=0;
    FOR(i,1,m) FOR(j,1,n) if ((i+j)%2==0 && tmp<numEven) res[i][j]=2*(++tmp);
    tmp=0;
    FOR(i,1,m) FOR(j,1,n) if ((i+j)%2!=0 && tmp<numOdd) res[i][j]=2*(++tmp)-1;
    solve(true);
}
void process(void) {
    scanf("%d%d%d",&q,&m,&n);
    if (n%2!=0) oddCol();
    if (m%2!=0) oddRow();
    bothEven();
}
int main(void) {
    process();
    return 220797;
}