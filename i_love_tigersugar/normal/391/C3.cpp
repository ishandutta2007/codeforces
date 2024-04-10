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

#define MAX   300300
const long long INF = (long long)1e18 + 7LL;

int numPerson, need;
vector<int> cost[MAX], all;
int cntLess[MAX];
long long sumNeed[MAX];

void init(void) {
    scanf("%d%d", &numPerson, &need);
    need = numPerson + 1 - need;

    all.clear();
    FOR(i, 0, numPerson + 1) cost[i].clear();

    REP(love, numPerson) {
        int p, e; scanf("%d%d", &p, &e);
        minimize(p, numPerson + 1);
        cost[p].push_back(e);
        all.push_back(e);
    }
}

long long getCost(int numWin) {
    if (numWin >= 2 && cntLess[numWin - 2] >= need) return sumNeed[numWin];
    if (cntLess[numWin] < need) return INF;

    long long res = 0;

    int special = need - (numWin >= 2 ? cntLess[numWin - 2] : 0);
    if (numWin < special) return INF;

    vector<int> remain;
    priority_queue<int> q;
    FOR(i, numWin - 1, numWin) FORE(jt, cost[i]) {
        res += *jt;
        q.push(*jt);
        while (q.size() > special) {
            remain.push_back(q.top());
            res -= q.top();
            q.pop();
        }
    }

    FOR(i, 0, numPerson + 1) if (i != numWin - 1 && i != numWin) FORE(jt, cost[i])
        remain.push_back(*jt);
    nth_element(remain.begin(), remain.begin() + numWin - special, remain.end());

    REP(i, numWin - special) res += remain[i];
    return res;
}

long long process(void) {
    if (need == 0) return 0;

    sort(ALL(all));
    sumNeed[0] = 0;
    REP(i, numPerson) sumNeed[i + 1] = sumNeed[i] + all[i];

    FOR(i, 0, numPerson + 1) sort(ALL(cost[i]));
    cntLess[0] = cost[0].size();
    FOR(i, 1, numPerson + 1) cntLess[i] = cntLess[i - 1] + cost[i].size();

    long long res = INF;
    FOR(numWin, 1, numPerson) minimize(res, getCost(numWin));
    return res < INF ? res : -1LL;
}

int main(void) {
    int numTest = 1; // scanf("%d", &numTest);
    REP(love, numTest) {
        init();
        printf("%lld\n", process());
    }
    return 0;
}

/*** BUBBLE TEA IS GREAT. MY CODE IS AMAZING :D ***/