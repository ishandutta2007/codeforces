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

const string YES = "YES";
const string NO = "NO";

#define MAX   100100
int left[MAX], right[MAX], res[MAX], n;
bool marked[MAX];

void noAnswer(void) {
    cout << NO << endl;
    exit(EXIT_SUCCESS);
}

void init(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &left[i]);
    FOR(i, 1, n) scanf("%d", &right[i]);
}

bool Compare(int x, int y) {
    return left[x] + right[x] < left[y] + right[y];
}

void process(void) {
    vector<int> indices;
    FOR(i, 1, n) indices.push_back(i);
    sort(ALL(indices), Compare);

    int j = 0;
    FORE(it, indices) {
        int cur = left[*it] + right[*it];
        while (j < n && left[indices[j]] + right[indices[j]] < cur) marked[indices[j++]] = true;
        int tmp = 0;
        FOR(i, 1, *it - 1) if (marked[i]) tmp++;
        if (tmp != left[*it]) noAnswer();
        tmp = 0;
        FOR(i, *it + 1, n) if (marked[i]) tmp++;
        if (tmp != right[*it]) noAnswer();
        res[*it] = n - cur;
    }
}

void checkAgain(void) {
    FOR(i, 1, n) if (res[i] < 1 || res[i] > n) noAnswer();
    FOR(i, 1, n) {
        FOR(j, 1, i - 1) if (res[j] > res[i]) left[i]--;
        FOR(j, i + 1, n) if (res[j] > res[i]) right[i]--;
        if (left[i] != 0 || right[i] != 0) noAnswer();
    }

    cout << YES << endl;
    FOR(i, 1, n) printf("%d ", res[i]); printf("\n");
}

int main(void) {
    init();
    process();
    checkAgain();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/