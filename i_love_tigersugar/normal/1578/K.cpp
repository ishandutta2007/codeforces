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

/** END OF TEMPLATE. DRINK A CUP OF TIGERSUGAR BEFORE READING MY CODE. **/

#define MAX   100100
#define NUM_BIT   30
const int MOD = (int)1e9 + 7;

int a[MAX], n;
long long need;
int cntBit[MAX][NUM_BIT], result;

void init(void) {
    scanf("%d%lld", &n, &need);
    FOR(i, 1, n) scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    REP(j, NUM_BIT) FOR(i, 1, n) cntBit[i][j] = cntBit[i - 1][j] + BIT(a[i], j);
}

bool addPattern(int pattern, int numFreeBit) {
    int sum = 0;
    long long cnt = 0;
    FOR(i, 1, n) {
        int needPattern = pattern ^ (a[i] >> numFreeBit);
        int low = needPattern << numFreeBit;
        int high = low | (MASK(numFreeBit) - 1);
        int l = lower_bound(a + 1, a + n + 1, low) - a;
        int r = upper_bound(a + 1, a + n + 1, high) - a - 1;
        if (l > r) continue;

        cnt += r - l + 1;
        if (cnt > 2 * need) return false;

        sum = (sum + 1LL * (pattern << numFreeBit) * (r - l + 1)) % MOD;
        REP(j, numFreeBit) {
            int tmp = cntBit[r][j] - cntBit[l - 1][j];
            if (BIT(a[i], j)) tmp = r - l + 1 - tmp;
            sum = (sum + 1LL * MASK(j) * tmp) % MOD;
        }
    }

    sum = (sum & 1) ? (sum + MOD) / 2 : sum / 2;
    assert(cnt % 2 == 0);
    cnt /= 2;

    if (cnt > need) return false;
    need -= cnt;
    result += sum;
    if (result >= MOD) result -= MOD;
    return true;
}

void process(void) {
    int pattern = 0;
    FORD(i, NUM_BIT - 1, 0)
        pattern = addPattern((pattern << 1) ^ 1, i) ? pattern << 1 : (pattern << 1) ^ 1;
    result = (result + 1LL * need * pattern) % MOD;
    cout << result << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/