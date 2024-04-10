#include<bits/stdc++.h>
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define FORD(i,b,a) for (int i=(b),_a=(a);i>=_a;i=i-1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
#define FORE(i,v) for (__typeof((v).begin()) i=(v).begin();i!=(v).end();i++)
#define ALL(v) (v).begin(),(v).end()
#define fi   first
#define se   second
#define MASK(i) (1LL<<(i))
#define BIT(x,i) (((x)>>(i))&1)
#define div   ___div
#define next   ___next
#define prev   ___prev
#define left   ___left
#define right   ___right
#define __builtin_popcount __builtin_popcountll
using namespace std;
template<class X,class Y>
    void minimize(X &x,const Y &y) {
        if (x>y) x=y;
    }
template<class X,class Y>
    void maximize(X &x,const Y &y) {
        if (x<y) x=y;
    }
template<class T>
    T Abs(const T &x) {
        return (x<0?-x:x);
    }

/* Author: Van Hanh Pham */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAX   5050
const long long INF = (long long)1e18 + 7LL;

vector<int> child[MAX];
int par[MAX], cost[MAX], discount[MAX];
long long minCost[MAX][MAX][2];
int numChild[MAX];
int n, limit;

void init(void) {
    scanf("%d%d", &n, &limit);
    FOR(i, 1, n) {
        scanf("%d%d", &cost[i], &discount[i]);
        if (i > 1) {
            scanf("%d", &par[i]);
            child[par[i]].push_back(i);
        }
    }

    memset(minCost, 0x3f, sizeof minCost);
}

long long tmp[MAX][2];

void dfs(int u) {
    FORE(it, child[u]) dfs(*it);

    numChild[u] = 0;
    REP(i, 2) minCost[u][0][i] = 0;

    FORE(it, child[u]) {
        int v = *it;

        REP(i, numChild[u] + 1) REP(j, 2) {
            tmp[i][j] = minCost[u][i][j];
            minCost[u][i][j] = INF;
        }

        REP(cu, numChild[u] + 1) REP(cv, numChild[v] + 1) REP(t, 2) {
//                if (tmp[cu][tu] + minCost[v][cv][tv] == 0 && u == 5 && v == 6)
//                    printf("ZERO %d", cu + cv);
                minimize(minCost[u][cu + cv][t], tmp[cu][t] + minCost[v][cv][t]);
            }
        numChild[u] += numChild[v];
    }

    REP(i, numChild[u] + 1) REP(j, 2) {
        tmp[i][j] = minCost[u][i][j];
        minCost[u][i][j] = INF;
    }

    REP(i, numChild[u] + 1) REP(j, 2) {
        //do not use
        minimize(minCost[u][i][0], tmp[i][0]);
        minimize(minCost[u][i][1], tmp[i][0]);
        //use with coupon
        minimize(minCost[u][i + 1][1], tmp[i][1] + cost[u] - discount[u]);
        //use without coupon
        minimize(minCost[u][i + 1][0], tmp[i][0] + cost[u]);
        minimize(minCost[u][i + 1][1], tmp[i][0] + cost[u]);
    }

    numChild[u]++;

//    printf("At %d\n", u);
//    printf("Size %d\n", numChild[u]);
//    REP(i, numChild[u] + 1) printf("Cost %d is %lld and %lld\n", i, minCost[u][i][0], minCost[u][i][1]);
}

void process(void) {
    dfs(1);
    FORD(i, n, 0) if (minCost[1][i][0] <= limit || minCost[1][i][1] <= limit) {
        printf("%d\n", i);
        return;
    }
    assert(false);
}

int main(void) {
#ifdef SKY
    //freopen("tmp.txt", "r", stdin);
#endif // SKY
    init();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/