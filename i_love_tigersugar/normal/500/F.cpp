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

struct Item {
    int cost, happiness, time;

    Item() {
        cost = happiness = time = 0;
    }

    Item(int t) {
        cost = happiness = 0; time = t;
    }

    void input(void) {
        scanf("%d%d%d", &cost, &happiness, &time);
    }

    bool operator < (const Item &i) const {
        return time < i.time;
    }
};

struct Query {
    int left, right, budget, answer;

    Query(int left = 0, int right = 0, int budget = 0) {
        this->left = left;
        this->right = right;
        this->budget = budget;
        this->answer = 0;
    }
};

#define MAX_ITEM   4040
#define MAX_QUERY   20020
#define MAX_HAPPY   4040
const int INF = (int)1e9 + 7;

Item items[MAX_ITEM];
Query queries[MAX_QUERY];
int numItem, numQuery, duration;
int maxHappyLeft[MAX_ITEM][MAX_HAPPY + 3], maxHappyRight[MAX_ITEM][MAX_HAPPY + 3];

void init(void) {
    scanf("%d%d", &numItem, &duration);
    FOR(i, 1, numItem) items[i].input();
    sort(items + 1, items + numItem + 1);

    scanf("%d", &numQuery);
    FOR(i, 1, numQuery) {
        int pos, budget; scanf("%d%d", &pos, &budget);
        int l = upper_bound(items + 1, items + numItem + 1, Item(pos - duration)) - items;
        int r = upper_bound(items + 1, items + numItem + 1, Item(pos)) - items;
        queries[i] = Query(l, r - 1, budget);
    }
}

void solve(int l, int r, const vector<int> &indices) {
    if (l > r) return;

    if (l == r) {
        int cost = items[r].cost;
        int happiness = items[r].happiness;
        FORE(it, indices) {
            Query &query = queries[*it];
            if (query.left <= query.right) query.answer = query.budget >= cost ? happiness : 0;
        }
        return;
    }

    int m = (l + r) >> 1;
    FOR(i, l, m) FOR(j, 0, MAX_HAPPY) maxHappyLeft[i][j] = -INF;
    FOR(i, m + 1, r) FOR(j, 0, MAX_HAPPY) maxHappyRight[i][j] = -INF;

    FOR(j, 0, MAX_HAPPY) maxHappyLeft[m][j] = items[m].cost <= j ? items[m].happiness : 0;
    FORD(i, m - 1, l) FOR(j, 0, MAX_HAPPY) {
        maxHappyLeft[i][j] = maxHappyLeft[i + 1][j];
        if (j >= items[i].cost)
            maximize(maxHappyLeft[i][j], maxHappyLeft[i + 1][j - items[i].cost] + items[i].happiness);
    }

    FOR(j, 0, MAX_HAPPY) maxHappyRight[m + 1][j] = items[m + 1].cost <= j ? items[m + 1].happiness : 0;
    FOR(i, m + 2, r) FOR(j, 0, MAX_HAPPY) {
        maxHappyRight[i][j] = maxHappyRight[i - 1][j];
        if (j >= items[i].cost)
            maximize(maxHappyRight[i][j], maxHappyRight[i - 1][j - items[i].cost] + items[i].happiness);
    }

    vector<int> leftIndices, rightIndices;
    FORE(it, indices) {
        Query &query = queries[*it];
        if (query.right <= m) leftIndices.push_back(*it);
        else if (query.left > m) rightIndices.push_back(*it);
        else if (query.left <= m && query.right > m) {
            query.answer = -INF;
            FOR(j, 0, query.budget)
                maximize(query.answer, maxHappyLeft[query.left][j] + maxHappyRight[query.right][query.budget - j]);
        }
    }

    solve(l, m, leftIndices);
    solve(m + 1, r, rightIndices);
}

void process(void) {
    vector<int> indices;
    FOR(i, 1, numQuery) indices.push_back(i);

    solve(1, numItem, indices);

    FOR(i, 1, numQuery) printf("%d\n", queries[i].answer);
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/