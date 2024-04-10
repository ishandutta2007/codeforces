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

const int BASE = MASK(8);
struct Number {
    unsigned char d[3];

    Number(int x = 0) {
        REP(i, 3) {
            d[i] = x & 255;
            x >>= 8;
        }
    }

    Number operator + (const Number &x) const {
        Number res;
        int rem = 0;
        REP(i, 3) {
            int tmp = rem + d[i] + x.d[i];
            res.d[i] = tmp & 255;
            rem = tmp > 255;
        }
        return res;
    }

    Number operator - (const Number &x) const {
        Number res;
        int rem = 0;
        REP(i, 3) {
            int tmp = d[i] - rem - x.d[i];
            res.d[i] = tmp < 0 ? tmp + BASE : tmp;
            rem = tmp < 0;
        }
        return res;
    }

    bool operator == (const Number &x) const {
        REP(i, 3) if (d[i] != x.d[i]) return false;
        return true;
    }

    int value(void) const {
        int res = 0;
        FORD(i, 2, 0) res = (res << 8) ^ d[i];
        return res;
    }
};

#define MAX   1000100
#define NUM_BIT   62
long long value[MAX], asked;
int left[MAX], right[MAX], n;
Number numZero[NUM_BIT][MAX];

void loadTree(void) {
    cin >> n >> asked;
    FOR(i, 2, n) {
        int p; long long w; cin >> p >> w;
        value[i] = value[p] ^ w;
    }
}

void prepare(void) {
    sort(value + 1, value + n + 1);
    REP(j, NUM_BIT) FOR(i, 1, n) {
        numZero[j][i] = numZero[j][i - 1];
        if (!BIT(value[i], j)) numZero[j][i] = numZero[j][i] + 1;
    }
    FOR(i, 1, n) right[i] = n;
}

void process(void) {
    long long res = 0;
    FORD(pos, NUM_BIT - 1, 0) {
        long long total = 0;
        FOR(i, 1, n) {
            int bit = BIT(value[i], pos);
            int zero = (numZero[pos][right[i]] - numZero[pos][left[i]]).value();
            int need = bit == 0 ? zero : right[i] - left[i] - zero;
            total += need;
            if (total > asked) break;
        }

        int newBit = total >= asked ? 0 : 1;
        if (asked > total) asked -= total;
        res |= (1LL * newBit) << pos;

        FOR(i, 1, n) {
            int need = newBit ^ BIT(value[i], pos);
            int zero = (numZero[pos][right[i]] - numZero[pos][left[i]]).value();
            if (need == 1) left[i] += zero;
            else right[i] = left[i] + zero;
        }
    }
    cout << res << endl;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    loadTree();
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/