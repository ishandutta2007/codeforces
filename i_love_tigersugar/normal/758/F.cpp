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

int floor(int a, int b) {
    assert(b != 0);
    return a / b;
}
int ceil(int a, int b) {
    assert(b != 0);
    return a / b + (a % b > 0);
}

#define MAXV   10001000
const int INF = (int)1e9 + 7;

int pw(int x, int k) {
    long long res = 1;
    long long mul = x;

    while (k > 0) {
        if (k & 1) res = res * mul;
        mul = mul * mul;
        k >>= 1;

        minimize(res, INF);
        minimize(mul, INF);
    }
    return res;
}

int gcd(int a, int b) {
    while (true) {
        if (a == 0) return b;
        if (b == 0) return a;
        if (a > b) a %= b; else b %= a;
    }
}
long long solve(int n, int l, int r) {
    int tmp = r - l + 1;
    if (n == 1) return tmp;
    if (n == 2) return 1LL * tmp * (tmp - 1);

    long long intRate = 0;
    FOR(p, 2, MAXV) {
        int tmp = pw(p, n - 1);
        if (tmp >= MAXV) break;

        int L = max(l, ceil(l, tmp));
        int R = min(r, floor(r, tmp));

        if (L <= R) intRate += R - L + 1;
    }

    long long fracRate = 0;
    FOR(q, 2, MAXV) {
        int pwQ = pw(q, n - 1);
        if (pwQ >= MAXV) break;

        vector<int> can;
        FOR(p, 1, MAXV) if (gcd(p, q) == 1) {
            int pwP = pw(p, n - 1);
            if (pwP >= MAXV) break;

            can.push_back(pwP);
        }

        int L = 0, R = 0;

        FORD(a, (MAXV - 1) / pwQ, 1) if (l <= a * pwQ && a * pwQ <= r) {
            while (L < can.size() && can[L] < ceil(l, a)) L++;
            while (R < can.size() && can[R] <= floor(r, a)) R++;

            if (L < R) fracRate += R - L;
        }
    }

    return intRate + fracRate;
}

int main(void) {
    int n, l, r;
    while (cin >> n >> l >> r) cout << solve(n, l, r) << endl;

    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/