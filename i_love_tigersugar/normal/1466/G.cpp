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

#define MAX   1000100
#define NMOD   2
const int MODULO[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};
const int BASE = 227;
int pw[NMOD][MAX];

void prepareHash(void) {
    REP(j, NMOD) {
        pw[j][0] = 1;
        FOR(i, 1, MAX - 1) pw[j][i] = 1LL * pw[j][i - 1] * BASE % MODULO[j];
    }
}

struct Hash {
    int value[NMOD];

    Hash(const string &s = "") {
        memset(value, 0, sizeof value);
        REP(j, NMOD) REP(i, s.size()) value[j] = (value[j] + 1LL * s[i] * pw[j][i]) % MODULO[j];
    }

    Hash concat(char c, int pos) const {
        Hash res;
        REP(i, NMOD) res.value[i] = (value[i] + 1LL * c * pw[i][pos]) % MODULO[i];
        return res;
    }

    Hash operator * (int step) const {
        Hash res;
        REP(i, NMOD) res.value[i] = 1LL * value[i] * pw[i][step] % MODULO[i];
        return res;
    }

    bool operator == (const Hash &x) const {
        REP(i, NMOD) if (value[i] != x.value[i]) return false;
        return true;
    }
};

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

const int MOD = (int)1e9 + 7;
const int INV_2 = (MOD + 1) / 2;
int pw2[MAX], invPw2[MAX];

void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

const int GOOD_LEVEL = 22;
Hash prefix[MAX], suffix[MAX];
string base, tower, levels[GOOD_LEVEL + 1];
int numLevel, numQuery, lastSmallLevel;
int sumInv2[26][MAX];
int needLevel[MAX];

void init(void) {
    cin >> numLevel >> numQuery >> base >> tower;
}

void prepare(void) {
    levels[0] = base;
    lastSmallLevel = 0;
    while (lastSmallLevel < numLevel && levels[lastSmallLevel].size() <= MAX) {
        lastSmallLevel++;
        levels[lastSmallLevel] =
            levels[lastSmallLevel - 1] + string(1, tower[lastSmallLevel - 1]) + levels[lastSmallLevel - 1];
    }

    FOR(i, 1, min(MAX - 1, (int)levels[lastSmallLevel].size())) {
        prefix[i] = prefix[i - 1].concat(levels[lastSmallLevel][i - 1], i - 1);
        suffix[i] = suffix[i - 1].concat(levels[lastSmallLevel][levels[lastSmallLevel].size() - i], i - 1);
    }

    pw2[0] = invPw2[0] = 1;
    FOR(i, 1, numLevel) {
        pw2[i] = (pw2[i - 1] << 1) % MOD;
        invPw2[i] = 1LL * invPw2[i - 1] * INV_2 % MOD;
        assert(1LL * pw2[i] * invPw2[i] % MOD == 1);

        REP(j, 26) {
            sumInv2[j][i] = sumInv2[j][i - 1];
            if (tower[i - 1] == j + 'a') sumInv2[j][i] = (sumInv2[j][i] + invPw2[i]) % MOD;
        }
    }

    FOR(i, 0, MAX - 1) {
        int j = base.size();
        int k = 0;
        while (j < i) {
            k++;
            j = 2 * j + 1;
        }
        needLevel[i] = k;
    }
}

int numMatch(char c, int minLevel, int maxLevel) {
    if (minLevel > maxLevel) return 0;
    return 1LL * pw2[maxLevel] * (sumInv2[c - 'a'][maxLevel] - sumInv2[c - 'a'][minLevel - 1] + MOD) % MOD;
}

int cntSubstrMatch(string &w) {
    if (w.size() > base.size()) return 0;
    int res = 0;
    REP(pos, base.size() - w.size() + 1) {
        bool ok = true;
        REP(j, w.size()) if (w[j] != base[pos + j]) {
            ok = false;
            break;
        }
        if (ok) res++;
    }
    return res;
}

Hash leftToRight[MAX], rightToLeft[MAX];
int query(int maxLevel, string &w) {
    if (maxLevel <= lastSmallLevel && w.size() > levels[maxLevel].size()) return 0;

    int res = 1LL * cntSubstrMatch(w) * pw2[maxLevel] % MOD;
    int lenW = w.size();

    leftToRight[lenW + 1] = Hash();
    FORD(i, lenW, 1) leftToRight[i] = (leftToRight[i + 1] * 1).concat(w[i - 1], 0);
    rightToLeft[0] = Hash();
    FOR(i, 1, lenW) rightToLeft[i] = (rightToLeft[i - 1] * 1).concat(w[i - 1], 0);

    FOR(i, 1, lenW) {
        bool okLeft = i == 1 || rightToLeft[i - 1] == suffix[i - 1];
        bool okRight = i == lenW || leftToRight[i + 1] == prefix[lenW - i];
        int minLevel = needLevel[max(i - 1, lenW - i)] + 1;
//        printf("pos %d need level %d\n", i, minLevel);
        if (okLeft && okRight) add(res, numMatch(w[i - 1], minLevel, maxLevel));
    }


    return res;
}

void process(void) {
    REP(love, numQuery) {
        int maxLevel;
        string w;
        cin >> maxLevel >> w;
        printf("%d\n", query(maxLevel, w));
    }
}

int main(void) {
    ios::sync_with_stdio(false);

    prepareHash();
    init();
    prepare();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/