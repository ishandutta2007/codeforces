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

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   200200

bool notPrime[MAX];
void eratosthene(void) {
    REP(i, 2) notPrime[i] = true;
    FOR(i, 2, MAX - 1) if (!notPrime[i])
        for (int j = 2 * i; j < MAX; j += i) notPrime[j] = true;
}

int main(void) {
    eratosthene();
    int n; cin >> n;
    cout << (n <= 2 ? 1 : 2) << endl;
    FOR(i, 2, n + 1) printf("%d ", notPrime[i] ? 2 : 1); printf("\n");
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/