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

#define MAX   111
#define NEED   11
const int INF = (int)1e9 + 7;

int cost[MAX][MAX];
vector<pair<int, int>> bestMid[MAX][MAX];
int numNode, need;

void init(void) {
    scanf("%d%d", &numNode, &need);
    FOR(i, 1, numNode) FOR(j, 1, numNode) scanf("%d", &cost[i][j]);

    need /= 2;
    FOR(i, 1, numNode) FOR(j, 1, numNode) {
        FOR(k, 2, numNode) if (k != i && k != j) bestMid[i][j].push_back(make_pair(cost[i][k] + cost[k][j], k));
        sort(ALL(bestMid[i][j]));
        while (bestMid[i][j].size() > NEED) bestMid[i][j].pop_back();
    }
}

int used[MAX];
int best, nodes[MAX];

int getBestMid(int i, int j) {
    FORE(it, bestMid[i][j]) if (used[it->se] == 0) return it->fi;
    return INF;
}
void updateResult(void) {
    int sum = 0;
    REP(i, need) {
        sum += getBestMid(nodes[i], nodes[i + 1]);
        if (sum >= best) return;
    }
    best = sum;
}

#define LOOP(i) for (nodes[i] = 1; nodes[i] <= numNode; nodes[i]++)

void process(void) {
    nodes[0] = nodes[need] = 1;
    used[1]++;
    best = INF;

    if (need == 1) updateResult();

    if (need == 2) {
        LOOP(1) {
            used[nodes[1]]++;
            updateResult();
            used[nodes[1]]--;
        }
    }

    if (need == 3) {
        LOOP(1) {
            used[nodes[1]]++;
            LOOP(2) {
                used[nodes[2]]++;
                updateResult();
                used[nodes[2]]--;
            }
            used[nodes[1]]--;
        }
    }

    if (need == 4) {
        LOOP(1) {
            used[nodes[1]]++;
            LOOP(2) {
                used[nodes[2]]++;
                LOOP(3) {
                    used[nodes[3]]++;
                    updateResult();
                    used[nodes[3]]--;
                }
                used[nodes[2]]--;
            }
            used[nodes[1]]--;
        }
    }

    if (need == 5) {
        LOOP(1) {
            used[nodes[1]]++;
            LOOP(2) {
                used[nodes[2]]++;
                LOOP(3) {
                    used[nodes[3]]++;
                    LOOP(4) {
                        used[nodes[4]]++;
                        updateResult();
                        used[nodes[4]]--;
                    }
                    used[nodes[3]]--;
                }
                used[nodes[2]]--;
            }
            used[nodes[1]]--;
        }
    }

    cout << best << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/