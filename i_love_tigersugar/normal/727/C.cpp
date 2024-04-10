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

/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   5555
int a[MAX], n;

int guess(int x, int y) {
    cout << "? " << x << " " << y << endl;
    int ans; cin >> ans;
    return ans;
}

void process(void) {
    int n; cin >> n;
    int x12 = guess(1, 2);
    int x23 = guess(2, 3);
    int x31 = guess(3, 1);
    a[1] = (x31 + x12 - x23) / 2;
    a[2] = (x12 + x23 - x31) / 2;
    a[3] = (x23 + x31 - x12) / 2;
    FOR(i, 4, n) a[i] = guess(1, i) - a[1];
    cout << "!";
    FOR(i, 1, n) cout << " " << a[i]; cout << endl;
}

int main(void) {
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/