#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) FOR(i, 0, n)
#define _ << " " <<

using namespace std;

typedef long long ll;
typedef pair<int, int> point;

const int MAXN = 1e5 + 5;

vector<int> ch[MAXN], e[MAXN];

int lo[MAXN], hi[MAXN], rev[MAXN];

int dp[MAXN];
int n, c[MAXN];

int cookie = 0;

void dfs(int u, int v) {
  rev[cookie] = v;
  lo[v] = cookie ++;
  for(auto w : e[v]) {
    if(u != w) {
      dfs(v, w);
      ch[v].push_back(w);
    }
  }
  hi[v] = cookie - 1;
}

bool check(int x) {
  if(dp[hi[x]] >= hi[x] - lo[x] + 1) return true;
  return false;
}

bool checkd(int x) {
  if(x == 0) return true;
  bool ret = true;
  if(dp[lo[x] - 1] < lo[x])
    ret = false;
  if(hi[x] != n - 1 && dp[n - 1] < n - 1 - hi[x])
    ret = false;
  if(hi[x] != n - 1 && c[rev[0]] != c[rev[n - 1]])
    ret = false;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  cin >> n;
  REP(i, n - 1) {
    int x, y; cin >> x >> y;
    e[x - 1].push_back(y - 1);
    e[y - 1].push_back(x - 1);
  }
  REP(i, n)
    cin >> c[i];
  dfs(0, 0);
  REP(i, n) {
    if(i == 0) {
      dp[i] = 1;
    }
    else if(c[rev[i]] != c[rev[i - 1]]) {
      dp[i] = 1;
    }
    else {
      dp[i] = dp[i - 1] + 1;
    }
  }
  REP(i, n) {
    bool ok = true;
    for(auto w : ch[i]) {
      if(!check(w))
        ok = false;
    }
    if(!checkd(i))
      ok = false;
    if(ok) {
      cout << "YES\n" << i + 1;
      return 0;
    }
  }
  cout << "NO";
}