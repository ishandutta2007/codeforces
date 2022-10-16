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

#define MAX   1000100
int n;
map<long long, int> cnt;
vector<pair<long long, int>> values;

bool notPrime[MAX];
vector<int> primes;
vector<long long> candidates;
int best;

void eratosthene(void) {
    REP(i, 2) notPrime[i] = true;
    FOR(i, 2, MAX - 1) if (!notPrime[i]) {
        primes.push_back(i);
        for (int j = 2 * i; j < MAX; j += i) notPrime[j] = true;
    }
}

void init(void) {
    cin >> n;
    REP(love, n) {
        long long x; cin >> x; cnt[x]++;
    }
    FORE(it, cnt) values.push_back(*it);
}

long long tmp[MAX];
void buildCandidate(long long l, long long r) {
    FOR(i, 0, r - l) tmp[i] = l + i;
    FORE(it, primes) {
        int prime = *it;
        int rem = l % prime;
        long long start = rem == 0 ? l : l + prime - rem;
        if (start <= r) candidates.push_back(prime);
        for (int j = start - l; j <= r - l; j += prime) {
            while (tmp[j] % prime == 0) tmp[j] /= prime;
        }
    }

    FOR(i, 0, r - l) if (tmp[i] > 1) candidates.push_back(tmp[i]);
    sort(ALL(candidates));
    candidates.resize(unique(ALL(candidates)) - candidates.begin());
}

long long getCost(long long value, long long candidate) {
    if (value < candidate) return candidate - value;
    long long tmp = value % candidate;
    return min(tmp, candidate - tmp);
}

void evaluate(long long candidate) {
    int res = 0;
    FORE(it, values) {
        long long cost = getCost(it->fi, candidate);
        if (res + cost * it->se >= best) return;
        res += it->se * cost;
    }
    best = res;
}

void process(void) {
    best = MAX;
    evaluate(2);
    evaluate(3);
    if (best == 0) {
        cout << best << endl;
        return;
    }

    buildCandidate(max(1LL, values[0].fi - best + 1), values[0].fi + best - 1);

    FORD(i, candidates.size() - 1, 0) {
        evaluate(candidates[i]);
        if (best == 0) break;
    }
    cout << best << endl;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);

    eratosthene();
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/