#include<bits/stdc++.h>
#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define FORE(i, v) for (__typeof((v).begin()) i = (v).begin(); i != (v).end(); i++)
#define ALL(v) (v).begin(), (v).end()
#define IS_INF(x)   (std::isinf(x))
#define IS_NAN(x)   (std::isnan(x))
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

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE.  **/

#define NMOD   2
#define MAX   1000100
const int BASE = 1 << 10;
const int MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};
int pw[NMOD][MAX];

void prepare(void) {
    REP(j, NMOD) {
        pw[j][0] = 1;
        FOR(i, 1, MAX - 1) pw[j][i] = 1LL * pw[j][i - 1] * BASE % MOD[j];
    }
}

struct Hash {
    int value[NMOD];

    Hash() {
        memset(value, 0, sizeof value);
    }

    Hash(char c, int pos) {
        REP(i, NMOD) value[i] = 1LL * c * pw[i][pos] % MOD[i];
    }

    Hash operator + (const Hash &x) const {
        Hash res;
        REP(i, NMOD) {
            res.value[i] = value[i] + x.value[i];
            if (res.value[i] >= MOD[i]) res.value[i] -= MOD[i];
        }
        return res;
    }

    Hash operator - (const Hash &x) const {
        Hash res;
        REP(i, NMOD) {
            res.value[i] = value[i] - x.value[i];
            if (res.value[i] < 0) res.value[i] += MOD[i];
        }
        return res;
    }

    Hash operator << (int x) const {
        Hash res;
        REP(i, NMOD) res.value[i] = 1LL * value[i] * pw[i][x] % MOD[i];
        return res;
    }

    bool operator == (const Hash &x) const {
        REP(i, NMOD) if (value[i] != x.value[i]) return false;
        return true;
    }
};

char input[MAX];
int n;
Hash leftToRight[MAX], rightToLeft[MAX];

bool isPalin(int l, int r) {
    if (l < 1 || r > n) return false;
    Hash lr = (leftToRight[r] - leftToRight[l - 1]) << (n - r);
    Hash rl = (rightToLeft[l] - rightToLeft[r + 1]) << (l - 1);
    return lr == rl;
}

void process(void) {
    scanf("%s", input + 1);
    n = strlen(input + 1);

    int maxSame = 0;
    FOR(i, 1, n / 2) {
        if (input[i] == input[n - i + 1]) maxSame++; else break;
    }
    if (maxSame == n / 2) {
        printf("%s\n", input + 1);
        return;
    }

    FOR(i, 0, n + 1) leftToRight[i] = rightToLeft[i] = Hash();
    FOR(i, 1, n) leftToRight[i] = leftToRight[i - 1] + Hash(input[i], i);
    FORD(i, n, 1) rightToLeft[i] = rightToLeft[i + 1] + Hash(input[i], n - i + 1);

    pair<int, int> best(maxSame, maxSame);
    // odd case
    FOR(i, maxSame + 1, n - maxSame) {
        // left
        int length = i - maxSame;
        int l = i - length + 1;
        int r = i + length - 1;
        if (2 * length - 1 + 2 * maxSame < n && isPalin(l, r)) {
            int L = r, R = maxSame;
            if (L + R > best.fi + best.se) best = {L, R};
        }

        // right
        length = n - i + 1 - maxSame;
        l = i - length + 1;
        r = i + length - 1;
        if (2 * length - 1 + 2 * maxSame < n && isPalin(l, r)) {
            int L = maxSame, R = n - l + 1;
            if (L + R > best.fi + best.se) best = {L, R};
        }
    }

    // even case
    FOR(i, maxSame + 1, n - maxSame - 1) if (input[i] == input[i + 1]) {
        // left
        int length = i - maxSame;
        int l = i - length + 1;
        int r = i + length;
        if (2 * length + 2 * maxSame < n && isPalin(l, r)) {
            int L = r, R = maxSame;
            if (L + R > best.fi + best.se) best = {L, R};
        }

        // right
        length = n - maxSame - i;
        l = i - length + 1;
        r = i + length;
        if (2 * length + 2 * maxSame < n && isPalin(l, r)) {
            int L = maxSame, R = n - l + 1;
            if (L + R > best.fi + best.se) best = {L, R};
        }
    }

    string res;
    FOR(i, 1, best.fi) res.push_back(input[i]);
    FOR(i, n - best.se + 1, n) res.push_back(input[i]);
    printf("%s\n", res.c_str());
}

int main(void) {
    prepare();
    int t; scanf("%d", &t);
    REP(love, t) process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/