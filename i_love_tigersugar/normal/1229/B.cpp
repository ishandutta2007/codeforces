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

#define MAX   100100
#define LOG   17
const int MOD = (int)1e9 + 7;

int numNode;
vector<int> adj[MAX];
int high[MAX], par[MAX][LOG + 1];
long long value[MAX], gcdRoot[MAX], gcdPar[MAX][LOG + 1];
int res;

void loadTree(void) {
  cin >> numNode;
  FOR(i, 1, numNode) cin >> value[i];
  REP(love, numNode - 1) {
    int u, v; cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
}

void dfs(int u) {
  FORE(it, adj[u]) if (*it != par[u][0]) {
    int v = *it;
    par[v][0] = u;
    high[v] = high[u] + 1;
    gcdRoot[v] = __gcd(gcdRoot[u], value[v]);
    dfs(v);
  }
}

void prepareLCA(void) {
  high[0] = -1; gcdRoot[1] = value[1];
  dfs(1);
  FOR(i, 1, numNode) gcdPar[i][0] = __gcd(value[i], value[par[i][0]]);
  FOR(j, 1, LOG) FOR(i, 1, numNode) {
    par[i][j] = par[par[i][j - 1]][j - 1];
    if (par[i][j] > 0) gcdPar[i][j] = __gcd(gcdPar[i][j - 1], gcdPar[par[i][j - 1]][j - 1]);
  }
}

bool divisible(long long x, long long y) {
  return y == 0 ? x == 0 : x % y == 0;
}

void calc(int u) {
  long long curValue = value[u];
  int v = u;
  while (true) {
    FORD(i, LOG, 0) if (par[v][i] > 0 && divisible(gcdPar[v][i], curValue)) v = par[v][i];
    res = (res + 1LL * (high[u] - high[v] + 1) * curValue) % MOD;
    if (v == 1) break;

    u = par[v][0]; v = u;
    curValue = __gcd(curValue, value[v]);
  }
}

void process(void) {
  prepareLCA();
  FOR(i, 1, numNode) calc(i);
  cout << res << endl;
}

int main(void) {
  ios::sync_with_stdio(false); cin.tie(NULL);
  loadTree();
  process();
  return 0;
}

/*** LOOK AT MY CODE. MY CODE IS AMAZING :D ***/