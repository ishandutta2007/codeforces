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

#define MAX   5050
const int MOD = (int)1e9 + 7;

int numGrass, numCow;
int grass[MAX], needType[MAX], needAmount[MAX];
int cntLess[MAX][MAX], cntLeft[MAX][MAX];

void init(void) {
    scanf("%d%d", &numGrass, &numCow);
    FOR(i, 1, numGrass) scanf("%d", &grass[i]);
    FOR(i, 1, numCow) {
        scanf("%d%d", &needType[i], &needAmount[i]);
        cntLess[needType[i]][needAmount[i]]++;
    }
}

#define SUM(x, y) ((x) + (y) >= MOD ? (x) + (y) - MOD : (x) + (y))
void update(pair<int, int> &best, const pair<int, int> &cur) {
    if (maximize(best.fi, cur.fi)) best.se = cur.se;
    else if (best.fi == cur.fi) best.se = SUM(best.se, cur.se);
}
void combine(pair<int, int> &cur, const pair<int, int> &tmp) {
    cur.fi += tmp.fi;
    cur.se = 1LL * cur.se * tmp.se % MOD;
}

pair<int, int> fixLastLeft(int pos) {
    int type = grass[pos];
    int numLeft = cntLeft[type][pos];
    int numRight = cntLeft[type][numGrass] - numLeft;

    if (cntLess[type][numLeft] == cntLess[type][numLeft - 1]) return {0, 0};

    int chooseLeft = cntLess[type][numLeft] - cntLess[type][numLeft - 1];
    int chooseRight = cntLess[type][numRight];
    if (numLeft <= numRight) chooseRight--;

    if (chooseRight > 0) return {2, chooseLeft * chooseRight};
    else return {1, chooseLeft};
}

pair<int, int> chooseOther(int cntLess[], int x, int y) {
    if (x > y) return chooseOther(cntLess, y, x);

    if (cntLess[y] == 0) return {0, 1};
    if (cntLess[x] == 0) return {1, cntLess[y]};
    if (cntLess[y] == 1) return {1, 2};
    return {2, cntLess[x] * (cntLess[y] - 1)};
}

void process(void) {
    FOR(i, 1, numGrass) FOR(j, 1, numGrass) cntLess[i][j] += cntLess[i][j - 1];
    FOR(i, 1, numGrass) FOR(j, 1, numGrass) cntLeft[i][j] = cntLeft[i][j - 1] + (grass[j] == i);

    pair<int, int> best(0, 1);
    FOR(i, 1, numGrass) {
        pair<int, int> tmp = fixLastLeft(i);
        FOR(j, 1, numGrass) if (j != grass[i])
            combine(tmp, chooseOther(cntLess[j], cntLeft[j][i], cntLeft[j][numGrass] - cntLeft[j][i]));

        update(best, tmp);
    }

    // no left
    pair<int, int> noLeft(0, 1);
    FOR(i, 1, numGrass) {
        int grass = cntLeft[i][numGrass];
        int choice = cntLess[i][grass];
        if (choice > 0) {
            noLeft.fi++; noLeft.se = 1LL * noLeft.se * choice % MOD;
        }
    }
    update(best, noLeft);

    if (best.fi == 0) best.se = 1;
    cout << best.fi << " " << best.se << endl;
}

int main(void) {
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/