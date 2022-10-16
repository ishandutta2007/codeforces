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

const char YES[] = "YES";
const char NO[] = "NO";

#define MAX   100100
char key[MAX];
int keyLength;
int next[MAX][26];

int numNode[3], curNode[3], numQuery;
pair<int, char> par[3][MAX];
pair<int, int> queries[MAX];
int*** dp;

void loadKey(void) {
    scanf("%d%d", &keyLength, &numQuery);
    scanf("%s", key + 1);
    REP(j, 26) next[keyLength][j] = next[keyLength + 1][j] = keyLength + 1;
    FORD(i, keyLength, 1) {
        REP(j, 26) next[i - 1][j] = next[i][j];
        next[i - 1][key[i] - 'a'] = i;
    }
}

void loadQuery(void) {
    REP(i, 3) numNode[i] = curNode[i] = 1;

    FOR(i, 1, numQuery) {
        char sign[5];
        int x; scanf("%s%d", sign, &x); x--;
        if (sign[0] == '+') {
            scanf("%s", sign);
            par[x][++numNode[x]] = make_pair(curNode[x], sign[0]);
            curNode[x] = numNode[x];
            queries[i] = make_pair(x, curNode[x]);
        } else {
            curNode[x] = par[x][curNode[x]].fi;
            queries[i] = make_pair(x, curNode[x]);
        }
    }
}

int minMatch(int x, int y, int z) {
    if (dp[x][y][z] >= 0) return dp[x][y][z];
    if (x == 1 && y == 1 && z == 1) return 0;
    int &res = dp[x][y][z];
    res = keyLength + 1;
    if (x > 1) {
        int t = minMatch(par[0][x].fi, y, z);
        minimize(res, next[t][par[0][x].se - 'a']);
    }
    if (y > 1) {
        int t = minMatch(x, par[1][y].fi, z);
        minimize(res, next[t][par[1][y].se - 'a']);
    }
    if (z > 1) {
        int t = minMatch(x, y, par[2][z].fi);
        minimize(res, next[t][par[2][z].se - 'a']);
    }
//    printf("match %d %d %d is %d\n", x, y, z, res);
    return res;
}

void process(void) {
    dp = new int**[numNode[0] + 1];
    REP(i, numNode[0] + 1) {
        dp[i] = new int*[numNode[1] + 1];
        REP(j, numNode[1] + 1) {
            dp[i][j] = new int[numNode[2] + 1];
            REP(k, numNode[2] + 1) dp[i][j][k] = -1;
        }
    }

    REP(i, 3) curNode[i] = 1;
    FOR(i, 1, numQuery) {
        curNode[queries[i].fi] = queries[i].se;
        int res = minMatch(curNode[0], curNode[1], curNode[2]);
//        printf("ANSWER %d %d %d\n", curNode[0], curNode[1], curNode[2]);
        printf("%s\n", res > keyLength ? NO : YES);
    }
}

int main(void) {
    loadKey();
    loadQuery();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/