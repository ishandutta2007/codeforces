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

class FenwickTree {
    vector<int> v;
    int n;

    public:
    FenwickTree(int n = 0) {
        this->n = n;
        v.assign(n + 7, 0);
    }

    void update(int x, int d) {
        for (; x <= n; x += x & -x) v[x] += d;
    }
    int get(int x) const {
        int res = 0;
        for (; x >= 1; x &= x - 1) res += v[x];
        return res;
    }

    int sumAfter(int x) const {
        return get(n) - get(x);
    }
};

#define GREATER   1
#define SMALLER   0
#define POSITIVE   1
#define NEGATIVE   0

#define CHAR(x) ((x) == '>' ? GREATER : SMALLER)
#define SIGN(x) ((x) > 0 ? POSITIVE : NEGATIVE)

struct Transform {
    int time, ch, sign;

    Transform() {
        time = ch = sign = 0;
    }

    Transform(int _time = 0, int _ch = 0, int _sign = 0) {
        time = _time; ch = _ch; sign = _sign;
    }
};

#define MAX   200200
int value[MAX], n, q;
pair<int, int> trans[MAX];
vector<Transform> transAt[MAX];
int res[MAX][2];

void init(void) {
    scanf("%d%d", &n, &q);
    FOR(i, 1, n) scanf("%d", &value[i]);
    FOR(i, 1, q) {
        char input[5]; scanf("%s", input);
        int x; scanf("%d", &x);
        trans[i] = make_pair(x, CHAR(input[0]));
        transAt[Abs(x)].push_back(Transform(i, CHAR(input[0]), SIGN(x)));
    }
}

int result(int value, int id) {
    if (trans[id].se == GREATER) return value > trans[id].fi ? -value : value;
    else return value < trans[id].fi ? -value : value;
}

bool alwaysChange(const Transform &t) {
    if (t.ch == GREATER && t.sign == NEGATIVE) return true;
    if (t.ch == SMALLER && t.sign == POSITIVE) return true;
    return false;
}

void precalc(void) {
    int lastZero = transAt[0].empty() ? 0 : transAt[0].back().time;
    FenwickTree bit(MAX - 1);
    FOR(i, 1, MAX - 1) FORE(jt, transAt[i]) if (alwaysChange(*jt)) bit.update(jt->time, 1);

    int lastPrev = 0;
    FOR(i, 1, MAX - 1) {
        FORE(jt, transAt[i]) if (alwaysChange(*jt)) bit.update(jt->time, -1);

        int lastConst = max(lastZero, lastPrev);
        FORE(it, transAt[i]) {
            bool ok = false;
            if (it->ch == GREATER && it->sign == NEGATIVE) ok = true;
            if (it->ch == SMALLER && it->sign == POSITIVE) ok = true;
            if (ok) maximize(lastConst, it->time);
        }

        REP(j, 2) {
            res[i][j] = lastConst == 0 ? j : SIGN(result(i, lastConst));
            int cnt = bit.sumAfter(lastConst);
            res[i][j] = cnt % 2 == 0 ? res[i][j] : res[i][j] ^ 1;
        }

        FORE(jt, transAt[i]) maximize(lastPrev, jt->time);
    }

    FOR(i, 1, n) {
        if (value[i] == 0) printf("0 ");
        else {
            int need = res[Abs(value[i])][SIGN(value[i])];
            printf("%d ", need == POSITIVE ? Abs(value[i]) : -Abs(value[i]));
        }
    }
}

int main(void) {
    init();
    precalc();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/