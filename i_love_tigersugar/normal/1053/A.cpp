#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x > y + eps) {
            x = y;
            return true;
        } else return false;
    }
template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        X eps = 1e-9;
        if (x + eps < y) {
            x = y;
            return true;
        } else return false;
    }
template<class T>
    T Abs(const T &x) {
        return (x < 0 ? -x : x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

const string YES = "YES";
const string NO = "NO";

int gcd(int a, int b) {
    while (true) {
        if (a == 0) return b;
        if (b == 0) return a;
        if (a >= b) a %= b; else b %= a;
    }
}

void printPoint(int x, int y) {
    cout << x << " " << y << endl;
}

void solve(int m, int n, int k) {
    if (2LL * m * n % k != 0) {
        cout << NO << endl;
        return;
    }
    cout << YES << endl;
    printPoint(0, 0);

    int a = gcd(2 * m, k);
    int b = k / a;
    if (a < 2) {
        b = gcd(2 * n, k);
        a = k / b;
        printPoint(m / a, 0);
        printPoint(0, 2 * n / b);
    } else {
        printPoint(2 * m / a, 0);
        printPoint(0, n / b);
    }
}

int main(void) {
     int a, b, c;
     while (cin >> a >> b >> c) solve(a, b, c);
     return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/