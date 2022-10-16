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

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   3333
const int MOD = (int)1e9 + 7;

#define NMOD   2
const int HASH_MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};
int pw[NMOD][MAX];

void prepare(void) {
    REP(j, NMOD) {
        pw[j][0] = 1;
        FOR(i, 1, MAX - 1) pw[j][i] = (1LL * pw[j][i - 1] << 8) % HASH_MOD[j];
    }
}

struct Hash {
    int value[NMOD];

    Hash(int x = 0) {
        memset(value, 0, sizeof value);
        REP(i, NMOD) value[i] = x;
    }

    Hash operator + (const Hash &x) const {
        Hash res;
        REP(i, NMOD) {
            res.value[i] = value[i] + x.value[i];
            if (res.value[i] >= HASH_MOD[i]) res.value[i] -= HASH_MOD[i];
        }
        return res;
    }

    Hash operator - (const Hash &x) const {
        Hash res;
        REP(i, NMOD) {
            res.value[i] = value[i] - x.value[i];
            if (res.value[i] < 0) res.value[i] += HASH_MOD[i];
        }
        return res;
    }

    Hash operator * (int k) const {
        Hash res;
        REP(i, NMOD) res.value[i] = 1LL * value[i] * pw[i][k] % HASH_MOD[i];
        return res;
    }

    bool operator < (const Hash &x) const {
        REP(i, NMOD) if (value[i] != x.value[i]) return value[i] < x.value[i];
        return false;
    }

    bool operator != (const Hash &x) const {
        REP(i, NMOD) if (value[i] != x.value[i]) return true;
        return false;
    }
};

const string BAD[] = {"0011", "0101", "1110", "1111"};

char input[MAX];
int n;
int cnt[MAX][MAX];
Hash hs[MAX];
pair<Hash, pair<int, int>> subs[MAX * MAX];
bool valid[MAX][MAX];

void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

bool ok(int pos) {
    REP(i, 4) {
        bool match = true;
        REP(j, 4) if (input[pos + j] != BAD[i][j]) {
            match = false; break;
        }
        if (match) return false;
    }
    return true;
}

Hash getHash(int l, int r) {
    return (hs[r] - hs[l - 1]) * (MAX - l);
}

void process(void) {
    scanf("%d", &n);
    FOR(i, 1, n) cnt[i][i - 1] = 1;

    int res = 0;
    FOR(i, 1, n) {
        int x; scanf("%d", &x);
        input[i] = x + '0';
        hs[i] = hs[i - 1] + Hash(input[i]) * i;
    }
    int numSub = n * (n + 1) / 2;
    int index = 0;
    FOR(i, 1, n) FOR(j, i, n) subs[++index] = make_pair(getHash(i, j), make_pair(i, j));
    assert(index == numSub);
    sort(subs + 1, subs + numSub + 1);
    FOR(i, 1, numSub) if (i == 1 || subs[i].fi != subs[i - 1].fi) {
        int l = subs[i].se.fi;
        int r = subs[i].se.se;
        valid[l][r] = true;
    }

    FOR(i, 1, n) {
        FOR(j, 1, i) {
            FOR(k, 1, 3) if (k <= i - j + 1) add(cnt[j][i], cnt[j][i - k]);
            if (4 <= i - j + 1 && ok(i - 3)) add(cnt[j][i], cnt[j][i - 4]);
//            printf("Count from %d to %d is %d\n", j, i, cnt[j][i]);
        }
        FOR(j, 1, i) if (valid[j][i]) add(res, cnt[j][i]);
        printf("%d\n", res);
    }
}

int main(void) {
    prepare();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/