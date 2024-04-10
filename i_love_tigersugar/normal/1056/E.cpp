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

#define MAX   1000100
#define NMOD   2
const int BASE = 227;
const int MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};
int pw[NMOD][MAX];

void prepareHash(void) {
    REP(i, NMOD) {
        pw[i][0] = 1;
        FOR(j, 1, MAX - 1) pw[i][j] = 1LL * pw[i][j - 1] * BASE % MOD[i];
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

    Hash move(int dis) const {
        Hash res;
        REP(i, NMOD) res.value[i] = 1LL * value[i] * pw[i][dis] % MOD[i];
        return res;
    }

    bool operator == (const Hash &x) const {
        REP(i, NMOD) if (value[i] != x.value[i]) return false;
        return true;
    }
};

void answer(long long x) {
    cout << x << endl;
    exit(EXIT_SUCCESS);
}

string binary;
char str[MAX];
Hash hs[MAX];
int length, numZero, numOne;

void init(void) {
    string t; cin >> binary >> t;
    length = t.size();
    FOR(i, 1, length) str[i] = t[i - 1];

    FOR(i, 1, length) hs[i] = hs[i - 1] + Hash(str[i], i);
    FORE(it, binary) if (*it == '0') numZero++; else numOne++;
}

bool equalSubstring(int i, int j, int len) {
    assert(i + len - 1 <= length);
    assert(j + len - 1 <= length);

    Hash hi = hs[i + len - 1] - hs[i - 1];
    Hash hj = hs[j + len - 1] - hs[j - 1];
    if (i < j) hi = hi.move(j - i);
    if (j < i) hj = hj.move(i - j);
    return hi == hj;
}

bool ok(int lengthZero) {
    if (1LL * numZero * lengthZero > length) return false;
    int tmp = length - numZero * lengthZero;
    if (tmp % numOne != 0) return false;
    int lengthOne = tmp / numOne;

    if (lengthZero < 1 || lengthOne < 1) return false;

    int zero = -1, one = -1;
    int id = 1;
    FORE(it, binary) {
        if (*it == '0') {
            if (zero < 0) zero = id;
            else if (!equalSubstring(zero, id, lengthZero)) return false;
            id += lengthZero;
        } else {
            if (one < 0) one = id;
            else if (!equalSubstring(one, id, lengthOne)) return false;
            id += lengthOne;
        }
    }
    assert(zero > 0 && one > 0);
    if (lengthZero == lengthOne && equalSubstring(zero, one, lengthZero)) return false;
    return true;
}

bool havePattern(int numPart) {
    if (length % numPart != 0) return false;
    int partLength = length / numPart;
    for (int i = 1; i <= length; i += partLength)
        if (!equalSubstring(i, 1, partLength)) return false;
    return true;
}

void process(void) {
    if (numZero == 0 || numOne == 0) answer(havePattern(binary.size()) ? 1 : 0);

    int res = 0;
    REP(lengthZero, length + 1) if (ok(lengthZero)) res++;
    cout << res << endl;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    prepareHash();
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/