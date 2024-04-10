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
int main(void) {
    int n; cin>>n;
    int numOdd=1;
    int curOdd=1;
    int curEven=2;
    bool firstHalf=true;
    REP(love,n) {
        REP(love,(n-numOdd)/2) {
            printf("%d ",curEven);
            curEven+=2;
        }
        REP(love,numOdd) {
            printf("%d ",curOdd);
            curOdd+=2;
        }
        REP(love,(n-numOdd)/2) {
            printf("%d ",curEven);
            curEven+=2;
        }
        printf("\n");
        if (numOdd==n) firstHalf=false;
        if (firstHalf) numOdd+=2;
        else numOdd-=2;
    }
    return 0;
}