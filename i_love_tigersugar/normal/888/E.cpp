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

#define MAX   111

int n, a[MAX], mod;

void init(void) {
    cin >> n >> mod;
    REP(i, n) cin >> a[i];
    REP(i, n) a[i] %= mod;

    if (n == 1) {
        cout << a[0] << endl;
        exit(EXIT_SUCCESS);
    }
}

void add(int &x, const int &y) {
    x += y;
    if (x >= mod) x -= mod;
}

vector<int> genSum(const vector<int> &v) {
    set<int> res;

    REP(i, MASK(v.size())) {
        int sum = 0;
        REP(j, v.size()) if (BIT(i, j)) add(sum, v[j]);
        res.insert(sum);
    }

    return vector<int>(ALL(res));
}

void process(void) {
    vector<int> left = genSum(vector<int>(a, a + n / 2));
    vector<int> right = genSum(vector<int>(a + n / 2, a + n));

    int best = 0;
    FORE(it, left) {
        int pos = lower_bound(ALL(right), mod - *it) - right.begin();
        if (pos > 0) maximize(best, (*it + right[pos - 1]) % mod);
        if (pos < right.size()) maximize(best, (*it + right.back()) % mod);
    }

    cout << best << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/