//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

const int MAXN = 100007;

bool was[MAXN];
int dp[MAXN], ans[MAXN];
vi G[MAXN];
vi POST;

int calc(int x, int n) {
  if(was[x]) return dp[x];
  was[x] = true;
  vi D(n), E(n);
  for(auto p : POST) {
    pii ttt;
    for(auto q : G[p]) {
      if(ttt.x < E[q]) {
        ttt.y = ttt.x;
        ttt.x = E[q];
      } else if(ttt.y < E[q]) {
        ttt.y = E[q];
      }
      D[p] += D[q];
    }
    if(x <= ttt.x + ttt.y + 1) D[p]++;
    else E[p] = ttt.x + 1;
  }
  return (dp[x] = D[0]);
}

bool odw[MAXN];

void dfs(int v) {
  odw[v] = true;
  for(auto w : G[v]) if(!odw[w]) dfs(w);
  POST.push_back(v);
}

void foo(int lft, int rht, pii s, int n) {
  if(lft >= rht-1) {
    ans[lft] = s.x;
    ans[rht] = s.y;
    return;
  }
  if(s.x == s.y) {
    for(int i=lft; i<=rht; i++) ans[i] = s.x;
    return;
  }
  int med = (lft + rht) >> 1;
  ans[med] = calc(med, n);
  foo(lft, med, {s.x, ans[med]}, n);
  foo(med, rht, {ans[med], s.y}, n);
}

int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i=1; i<n; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(0);
  int upp = calc(n, n);
  foo(1, n, {n, upp}, n);
  for(int i=1; i<=n; i++) cout << ans[i] << "\n";
  return 0;
}