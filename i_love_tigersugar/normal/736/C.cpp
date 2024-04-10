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

/* Author: Van Hanh Pham - skyvn97 */

/** END OF TEMPLATE - ACTUAL SOLUTION COMES HERE **/

#define MAXN   110
#define MAXK   25

const int mod = (int)1e9 + 7;

int n, m;
vector<int> adj[MAXN];
int dp[MAXN][MAXK][MAXK];
int tmp[MAXN][MAXK][MAXK];

void loadTree(void) {
    scanf("%d%d", &n, &m);

    if (m == 0) {
        printf("1\n");
        exit(0);
    }

    REP(love, n - 1) {
        int u, v; scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void add(int &x, const int &y) {
    x += y;
    if (x >= mod) x -= mod;
}

void dfs(int u, int par) {
    int tmp[2][MAXK][MAXK];
    memset(tmp, 0, sizeof tmp);

    int cur = 0;
    int next = 1;
    tmp[cur][m + 1][0] = 1;

    FORE(it, adj[u]) if (*it != par) {
        dfs(*it, u);
        REP(i, m + 2) REP(j, m + 2) if (tmp[cur][i][j] > 0) {
            REP(k, m + 2) REP(l, m + 2) {
                if (l <= m)add(tmp[next][min(i, k + 1)][max(j, l + 1)], 1LL * tmp[cur][i][j] * dp[*it][k][l] % mod);
            }
            tmp[cur][i][j] = 0;
        }
        cur ^= 1;
        next ^= 1;
    }

    REP(i, m + 2) REP(j, m + 2) {
        add(dp[u][0][0], tmp[cur][i][j]);
        if (i + max(j - 1, 0) <= m) add(dp[u][i][0], tmp[cur][i][j]);
        else add(dp[u][i][max(j, 1)], tmp[cur][i][j]);
    }

//    printf("DP of %d\n", u);
//    REP(i, m + 2) REP(j, m + 1) if (dp[u][i][j] != 0) printf("DP %d %d %d is %d\n", u, i, j, dp[u][i][j]);
}

void process(void) {
    dfs(1, -1);
    int res = 0;
    REP(i, m + 1) add(res, dp[1][i][0]);
    printf("%d\n", res);
}

int main(void) {
    loadTree();
    process();
    return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/