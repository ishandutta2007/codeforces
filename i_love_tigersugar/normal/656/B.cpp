#include<bits/stdc++.h>
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
const int nTry=(int)3e7;
int m[222],r[222],n;
bool ok(int x) {
    REP(i,n) if (x%m[i]==r[i]) return (true);
    return (false);
}
int main(void) {
    srand(time(NULL));
    scanf("%d",&n);
    REP(i,n) scanf("%d",&m[i]);
    REP(i,n) scanf("%d",&r[i]);
    int nSucc=0;
    REP(love,nTry) if (ok(love)) nSucc++;
    printf("%.7lf\n",1.0*nSucc/nTry);
    return 0;
}