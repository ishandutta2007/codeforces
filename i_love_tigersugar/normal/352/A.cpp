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
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
int main(void) {
    int n;
    int c0=0;
    int c5=0;
    scanf("%d",&n);
    REP(love,n) {
        int t;
        scanf("%d",&t);
        if (t==0) c0++; else c5++;
    }
    if (c0==0) {
        printf("-1\n");
        return 0;
    }
    if (c5<9) {
        printf("0\n");
        return 0;
    }
    REP(love,c5-c5%9) printf("5");
    REP(love,c0) printf("0");
    printf("\n");
    return 0;
}