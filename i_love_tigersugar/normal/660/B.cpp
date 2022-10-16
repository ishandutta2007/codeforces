#include<bits/stdc++.h>
#define MAX   1111
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
int a[4][MAX],n,m;
int main(void) {
    scanf("%d%d",&n,&m);
    int cnt=0;
    FOR(i,1,n) {
        a[0][i]=++cnt;
        a[3][i]=++cnt;
    }
    FOR(i,1,n) {
        a[1][i]=++cnt;
        a[2][i]=++cnt;
    }
    vector<int> pos;
    FOR(i,1,n) {
        pos.push_back(a[1][i]);
        pos.push_back(a[0][i]);
        pos.push_back(a[2][i]);
        pos.push_back(a[3][i]);
    }
    FORE(it,pos) if (*it<=m) printf("%d ",*it); printf("\n");
    return 0;
}