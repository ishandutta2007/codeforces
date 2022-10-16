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

int inverse(int x, int mod) {
    int res = 1, mul = x, k = mod - 2;
    while (k > 0) {
        if (k & 1) res = 1LL * res * mul % mod;
        mul = 1LL * mul * mul % mod;
        k >>= 1;
    }
    return res;
}

#define NMOD   2
const int MOD[] = {(int)1e9 + 2277, (int)1e9 + 5277, (int)1e9 + 8277, (int)1e9 + 9277};

struct Number {
    int value[NMOD];

    Number(int x = 0) {
        REP(i, NMOD) value[i] = x;
    }

    Number operator + (const Number &x) const {
        Number res;
        REP(i, NMOD) {
            res.value[i] = value[i] + x.value[i];
            if (res.value[i] >= MOD[i]) res.value[i] -= MOD[i];
        }
        return res;
    }

    Number operator - (const Number &x) const {
        Number res;
        REP(i, NMOD) {
            res.value[i] = value[i] - x.value[i];
            if (res.value[i] < 0) res.value[i] += MOD[i];
        }
        return res;
    }

    Number operator * (const Number &x) const {
        Number res;
        REP(i, NMOD) res.value[i] = 1LL * value[i] * x.value[i] % MOD[i];
        return res;
    }

    bool isZero(void) const {
        REP(i, NMOD) if (value[i] != 0) return false;
        return true;
    }
};

ostream& operator << (ostream &os, const Number &n) {
    int tmp = n.value[0];
    if (tmp > 100) tmp = tmp - MOD[0];
    return os << tmp;
}

Number getInverse(int x) {
    Number res;
    REP(i, NMOD) res.value[i] = inverse(x, MOD[i]);
    return res;
}

#define MAX   300300
bool notPrime[MAX], notPrimeProduct[MAX];
vector<pair<int, int> > primeProducts;
int countDiv[MAX];
Number inv[MAX];

int n, numSize;
int sizeID[MAX];
Number *sumComb[MAX];

void eratosthene(void) {
    REP(i, 2) notPrime[i] = true;
    FOR(i, 2, MAX - 1) if (!notPrime[i])
        for (int j = 2 * i; j < MAX; j += i) notPrime[j] = true;
    int numPrime = 0;
    REP(i, MAX) if (!notPrime[i]) numPrime++;

    notPrimeProduct[0] = true;
    for (int i = 1; 1LL * i * i < MAX; i++) if (!notPrime[i])
        for (int j = i * i; j < MAX; j += i * i) notPrimeProduct[j] = true;

    FOR(i, 1, MAX - 1) if (!notPrime[i])
        for (int j = i; j < MAX; j += i) countDiv[j]++;
    REP(i, MAX) if (!notPrimeProduct[i]) primeProducts.push_back(make_pair(i, countDiv[i] % 2));

    memset(countDiv, 0, sizeof countDiv);
    FOR(i, 1, MAX - 1) inv[i] = getInverse(i);
}

void init(void) {
    scanf("%d", &n);
    int gcdAll = 0;
    REP(love, n) {
        int x; scanf("%d", &x); countDiv[x]++;
        gcdAll = gcdAll == 0 ? x : __gcd(gcdAll, x);
    }

    if (gcdAll > 1) {
        cout << -1 << endl;
        exit(EXIT_SUCCESS);
    }
}

void calcSumComb(Number sum[], int n) {
    sum[0] = 0;
    Number comb = 1;
    FOR(i, 1, n) {
        comb = comb * Number(n - i + 1);
        comb = comb * inv[i];
        sum[i] = sum[i - 1] + comb;
    }
}

void prepare(void) {
    FOR(i, 1, MAX - 1) for (int j = 2 * i; j < MAX; j += i) countDiv[i] += countDiv[j];

    vector<int> sizes;
    FOR(i, 1, MAX - 1) if (countDiv[i] > 0) sizes.push_back(countDiv[i]);
    sort(ALL(sizes));
    sizes.resize(unique(ALL(sizes)) - sizes.begin());

    memset(sizeID, -1, sizeof sizeID);
    numSize = sizes.size();
    REP(i, numSize) {
        sizeID[sizes[i]] = i;
        sumComb[i] = new Number[sizes[i] + 1];
        calcSumComb(sumComb[i], sizes[i]);
    }
}

Number getSumComb(int k, int n) {
    if (n == 0) return 0;
    if (k > n) k = n;
    assert(sizeID[n] >= 0);
    return sumComb[sizeID[n]][k];
}

Number countCoprime(int k) {
    Number res = 0;
    FORE(it, primeProducts) {
        Number tmp = getSumComb(k, countDiv[it->fi]);
        if (it->se == 0) res = res + tmp; else res = res - tmp;
    }
    return res;
}

int solve(void) {
    int L = 1, R = n;
    while (true) {
        if (L == R) return L;
        if (R - L == 1) return !countCoprime(L).isZero() ? L : R;
        int M = (L + R) >> 1;
        if (!countCoprime(M).isZero()) R = M; else L = M + 1;
    }
}

int main(void) {
#ifdef SKY
    freopen("tmp.txt", "r", stdin);
#endif // SKY
    eratosthene();
    init();
    prepare();
    cout << solve() << endl;
    return 0;
}
/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/