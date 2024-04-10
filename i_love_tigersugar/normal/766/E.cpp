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

#define MAX   100100
#define NUM_BIT   22

vector<int> adj[MAX];
int value[MAX], sumXor[MAX];
int cntBit[MAX][NUM_BIT][2];
int n;
long long res, cntWay[MAX][NUM_BIT][2];

void loadTree(void) {
    scanf("%d", &n);
    FOR(i, 1, n) scanf("%d", &value[i]);
    REP(love, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u, int par) {
    REP(i, NUM_BIT) cntBit[u][i][BIT(sumXor[u], i)]++;

    FORE(it, adj[u]) if (*it != par) {
        int v = *it;
        sumXor[v] = sumXor[u] ^ value[v];
        dfs(v, u);
        REP(i, NUM_BIT) REP(j, 2) REP(k, 2) cntWay[u][i][j ^ k] += 1LL * cntBit[u][i][j] * cntBit[v][i][k];
        REP(i, NUM_BIT) REP(j, 2) cntBit[u][i][j] += cntBit[v][i][j];
    }

    REP(i, NUM_BIT) res += 1LL * cntWay[u][i][BIT(value[u], i) ^ 1] * MASK(i);
}

void process(void) {
    sumXor[1] = value[1];
    dfs(1, -1);
    FOR(i, 1, n) res += value[i];
    cout << res << endl;
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/