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

#define MAX   300300
#define VALUE   150

int value[MAX], sum[MAX], cnt[MAX][2], n;
int firstNonZero[MAX];
int firstSumGreater[MAX][VALUE + 7];
int firstValueGreater[MAX];

void init(void) {
    cin >> n;
    FOR(i, 1, n) {
        long long x; cin >> x;
        value[i] = __builtin_popcount(x);
        sum[i] = sum[i - 1] + value[i];
    }
}

void process(void) {
    firstNonZero[n] = n + 1;
    FORD(i, n - 1, 0) firstNonZero[i] = value[i + 1] > 0 ? i + 1 : firstNonZero[i + 1];
    FOR(i, 0, n) {
        int index = i;
        REP(j, VALUE + 1) {
            while (index <= n && sum[index] < sum[i] + j) index = firstNonZero[index];
            firstSumGreater[i][j] = index;
        }
    }
    firstValueGreater[n] = n + 1;
    stack<int> st;
    FORD(i, n, 1) {
        while (!st.empty() && value[st.top()] <= value[i]) st.pop();
        firstValueGreater[i] = st.empty() ? n + 1 : st.top();
        st.push(i);
    }
    REP(j, 2) FOR(i, 1, n) cnt[i][j] = cnt[i - 1][j] + (sum[i] % 2 == j);

    long long res = 0;
    FOR(left, 1, n) {
        int maxIndex = left;
        while (maxIndex <= n) {
            int maxValue = value[maxIndex];
            int minRight = firstSumGreater[left - 1][maxValue * 2];
            int maxRight = firstValueGreater[maxIndex] - 1;
            maximize(minRight, maxIndex);
            int reqMod = sum[left - 1] % 2;
            if (maxRight >= minRight) res += cnt[maxRight][reqMod] - cnt[minRight - 1][reqMod];
            maxIndex = maxRight + 1;
        }
    }
    cout << res << endl;
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL);
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/