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

const int MOD = (int)1e9 + 7;
void add(int &x, const int &y) {
    x += y;
    if (x >= MOD) x -= MOD;
}

#define MAX_PW   60
#define MAX_STEP   10010
int prob[MAX_PW][MAX_STEP];
int inv[MAX_PW + 3];
vector<int> cacheProb[MAX_PW];

int inverse(int x) {
    int res = 1, mul = x, k = MOD - 2;
    while (k > 0) {
        if (k & 1) res = 1LL * res * mul % MOD;
        mul = 1LL * mul * mul % MOD;
        k >>= 1;
    }
    return res;
}

#define INVERSE(x) (inv[x] < 0 ? inv[x] = inverse(x) : inv[x])

vector<int> calcProb(int start, int step) {
    if (!cacheProb[start].empty()) return cacheProb[start];

    memset(prob, 0, sizeof prob);
    prob[start][0] = 1;
    REP(i, step) REP(j, start + 1) if (prob[j][i] > 0) {
        int tmp = INVERSE(j + 1);
        REP(k, j + 1) add(prob[k][i + 1], 1LL * prob[j][i] * tmp % MOD);
    }

    vector<int> res(start + 1);
    REP(i, start + 1) res[i] = prob[i][step];
    cacheProb[start] = res;
    return res;
}

vector<pair<long long, int>> factor(long long x) {
    vector<pair<long long, int>> res;
    for (int i = 2; 1LL * i * i <= x; i++) if (x % i == 0) {
        res.push_back(make_pair(i, 0));
        while (x % i == 0) {
            x /= i;
            res.back().se++;
        }
    }
    if (x > 1) res.push_back(make_pair(x, 1));
    return res;
}

int numFact;
pair<long long, int> facts[MAX_PW];
vector<int> haveProb[MAX_PW];

void backtrack(int pos, long long value, int prob, int &res) {
    if (pos >= numFact) return add(res, value % MOD * prob % MOD);

    long long mul = 1;
    REP(i, facts[pos].se + 1) {
        backtrack(pos + 1, value * mul, 1LL * prob * haveProb[pos][i] % MOD, res);
        mul *= facts[pos].fi;
    }
}

int solve(long long n, int k) {
    if (n == 1) return 1;

    memset(inv, -1, sizeof inv);
    REP(i, MAX_PW) cacheProb[i].clear();

    vector<pair<long long, int>> primes = factor(n);
    numFact = primes.size();
    REP(i, numFact) facts[i] = primes[i];
    REP(i, numFact) haveProb[i] = calcProb(facts[i].se, k);

//    printf("%d facts: ", numFact);
//    REP(i, numFact) printf("(%lld, %d) ", facts[i].fi, facts[i].se); printf("\n");

    int res = 0;
    backtrack(0, 1, 1, res);
    return res;
}

int main(void) {
    long long n; int k; while (cin >> n >> k) cout << solve(n, k) << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/