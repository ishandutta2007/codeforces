#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 200200;
const int B = 61;
const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

struct Edge {
  int b;
  llint w;
  int i;
};

vector<Edge> E[MAX];
llint pre[MAX];
int disc[MAX], tick;

enum Color {WHITE, GRAY, BLACK};
Color color[MAX];
vector<llint> cycles;

vector<pair<int, int>> cnt_nodes[MAX];
vector<pair<int, int>> cnt_paths;

int dfs(int x, int dad_edge) {
  color[x] = GRAY;
  disc[x] = tick++;
  int lw = disc[x];

  cnt_nodes[x] = vector<pair<int, int>>(B, {0, 0});
  REP(i, B)
    if ((pre[x] >> i) & 1) {
      cnt_nodes[x][i].second++;
    } else {
      cnt_nodes[x][i].first++;
    }
  
  for (auto& e: E[x]) {
    if (e.i == dad_edge) continue;

    int y = e.b;
    llint w = e.w;
    
    if (color[y] == WHITE) {
      pre[y] = pre[x] ^ w;
      int lwy = dfs(y, e.i);
      lw = min(lw, lwy);

      REP(i, B) {
        int w0 = add(mul(cnt_nodes[x][i].first, cnt_nodes[y][i].first),
                     mul(cnt_nodes[x][i].second, cnt_nodes[y][i].second));
        int w1 = add(mul(cnt_nodes[x][i].first, cnt_nodes[y][i].second),
                     mul(cnt_nodes[x][i].second, cnt_nodes[y][i].first));
        
        cnt_paths[i].first = add(cnt_paths[i].first, w0);
        cnt_paths[i].second = add(cnt_paths[i].second, w1);
        
        cnt_nodes[x][i].first += cnt_nodes[y][i].first;
        cnt_nodes[x][i].second += cnt_nodes[y][i].second;
      }
        
    } else if (color[y] == GRAY) {
      lw = min(lw, disc[y]);
      cycles.push_back(pre[x] ^ pre[y] ^ w);
    }
  }

  color[x] = BLACK;
  return lw;
}

int pw2[B];
int C[B][B];

vector<pair<int, int>> getCounts(vector<llint> a) {
  int n = a.size();
  int m = 0;
  for (int j = B-1; j >= 0; --j) {
    int k = -1;
    for (int i = m; i < n; ++i)
      if (a[i]&(1LL<<j)) {
        if (k != -1) a[i] ^= a[k]; else
          k = i;
      }
    if (k != -1) swap(a[m++], a[k]);
  }


  vector<pair<int, int>> ret;
  REP(j, B) {
    int cnt = 0;
    REP(i, m) cnt += (a[i] >> j) & 1;
    int ways = 0;
    for (int i = 1; i <= cnt; i += 2)
      ways = add(ways, C[cnt][i]);
    ways = mul(ways, pw2[m - cnt]);
    ret.push_back({sub(pw2[m], ways), ways});
  }
  return ret;
}

int main(void) {
  pw2[0] = 1;
  REP(i, B-1) pw2[i+1] = mul(pw2[i], 2);
  REP(i, B) {
    C[i][0] = 1;
    FOR(j, 1, i+1)
      C[i][j] = add(C[i-1][j], C[i-1][j-1]);
  }

  int N, M;
  scanf("%d %d", &N, &M);
  REP(i, M) {
    int a, b;
    llint w;
    scanf("%d %d %lld", &a, &b, &w);
    --a, --b;
    E[a].push_back({b, w, i});
    E[b].push_back({a, w, i});
  }

  int ans = 0;
  REP(i, N)
    if (color[i] == WHITE) {
      cycles.clear();
      cnt_paths = vector<pair<int, int>>(B, {0, 0});
      dfs(i, -1);
      auto counts = getCounts(cycles);
      
      REP(j, B) {
        int w = add(mul(cnt_paths[j].first, counts[j].second),
                    mul(cnt_paths[j].second, counts[j].first));
        ans = add(ans, mul(w, pw2[j]));
      }
    }

  printf("%d\n", ans);
  return 0;
}