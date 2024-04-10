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

#define MAX   200200
#define MOD   10

vector<int> adj[MAX];
int high[MAX];
int n, mod;
int countChild[MAX][MOD];
long long sumChild[MAX][MOD];
long long countWay[MOD];
long long totalWay[MOD];

void loadTree(void) {
    scanf("%d%d", &n, &mod);
    REP(love, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u, int par) {
    countChild[u][high[u] % mod] = 1;
    sumChild[u][high[u] % mod] = high[u];

    FORE(it, adj[u]) if (*it != par) {
        int v = *it;
        high[v] = high[u] + 1;
        dfs(v, u);

        REP(i, mod) REP(j, mod) {
            long long numWay = 1LL * countChild[u][i] * countChild[v][j];
            long long sumWay = 1LL * countChild[v][j] * (sumChild[u][i] - 1LL * countChild[u][i] * high[u])
                            + 1LL * countChild[u][i] * (sumChild[v][j] - 1LL * countChild[v][j] * high[u]);

            int expMod = i + j - 2 * high[u]; expMod = (expMod % mod + mod) % mod;
            countWay[expMod] += numWay;
            totalWay[expMod] += sumWay;

        }

        REP(i, mod) {
            countChild[u][i] += countChild[v][i];
            sumChild[u][i] += sumChild[v][i];
        }
    }
}

void process(void) {
    dfs(1, -1);
    long long res = 0;
    //REP(i, mod) cerr << totalWay[i] << " " << countWay[i] << endl;
    REP(i, mod) res += (totalWay[i] + (i == 0 ? 0 : mod - i) * countWay[i]) / mod;
    cout << res << endl;
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/