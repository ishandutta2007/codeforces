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

#define MAX   600600
#define LOG   20

int n;
long long length, posA[MAX], posB[MAX], values[MAX];
int first[MAX], last[MAX];

int rmq[MAX][LOG + 1];
int lg2[MAX];

void init(void) {
    cin >> n >> length;
    FOR(i, 1, n) cin >> posA[i];
    FOR(i, 1, n) cin >> posB[i];
    sort(posA + 1, posA + n + 1);
    sort(posB + 1, posB + n + 1);

    FOR(i, 1, n) {
        while (MASK(lg2[i]) <= i) lg2[i]++;
        lg2[i]--;
    }
}

int getMin(int l, int r) {
    assert(l <= r);
    int k = lg2[r - l + 1];
    return min(rmq[l][k], rmq[r - MASK(k) + 1][k]);
}

bool ok(long long range, long long source[], long long target[]) {
    FOR(i, 1, n) values[i] = target[i] - length;
    FOR(i, 1, n) values[i + n] = target[i];
    FOR(i, 1, n) values[i + n * 2] = target[i] + length;

    int j = 1;
    FOR(i, 1, n) {
        long long tmp = source[i] - range;
        while (j <= 3 * n && values[j] < tmp) j++;
        if (j > 3 * n || values[j] > source[i] + range) return false;
        first[i] = j;
    }
    j = 3 * n;
    FORD(i, n, 1) {
        long long tmp = source[i] + range;
        while (j >= 1 && values[j] > tmp) j--;
        if (j == 0 || values[j] < source[i] - range) return false;
        last[i] = j;
    }
    FOR(i, 1, n) if (first[i] > last[i]) return false;

    FOR(i, 1, n) rmq[i][0] = last[i] - i;
    FOR(j, 1, LOG) FOR(i, 1, n - MASK(j) + 1) rmq[i][j] = min(rmq[i][j - 1], rmq[i + MASK(j - 1)][j - 1]);

    j = 1;
    FOR(i, 1, n) {
        maximize(j, i);
        while (j < n && (source[j + 1] + range) - (source[i] - range) + 1 < length) j++;
        int tmp = getMin(i, j);
        if (tmp < first[i] - i) return false;
    }
    return true;
}

bool ok(long long range) {
    return ok(range, posA, posB) && ok(range, posB, posA);
}

long long solve(void) {
    long long L = 0, R = length;
    while (true) {
        if (L == R) return R;
        if (R - L == 1) return ok(L) ? L : R;
        long long M = (L + R) >> 1;
        if (ok(M)) R = M; else L = M + 1;
    }
}

int main(void) {
    ios::sync_with_stdio(false);
    init();
    cout << solve() << endl;
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/