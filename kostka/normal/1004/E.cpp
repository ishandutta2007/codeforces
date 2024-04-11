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

const int MAXN = 100007;
bool vis[MAXN];
int dis[MAXN], fat[MAXN], dp[MAXN];
vector <pii> G[MAXN];

void dfs(int v) {
  vis[v] = true;
  for(auto ele : G[v]) {
    int w, d;
    tie(w, d) = ele;
    if(!vis[w]) {
      fat[w] = v;
      dis[w] = dis[v] + d;
      dfs(w);
    }
  }
}

int chosen = 0;

int start, odl;

bool dfs2(int v) {
  vis[v] = true;
  int wrong = 0;
  dp[v] = 0;
  for(auto ele : G[v]) {
    int w, d;
    tie(w, d) = ele;
    if(!vis[w]) {
      if(dfs2(w) == false) return false;
      if(dp[w] == -1) wrong++;
      else if (dp[w] + d > odl) {
        chosen++;
        wrong++;
      }
      else dp[v] = max(dp[v], dp[w] + d);
    }
  }
  if(v == start) wrong--;
  if(wrong > 1) return false;
  if(v == start) wrong = max(wrong, 1);
  if(wrong > 0) {
    chosen++;
    dp[v] = -1;
  }
  return true;
}

bool check(int _odl, int ct, int k) {
  chosen = 0;
  start = ct;
  odl = _odl;
  return dfs2(ct) and chosen <= k;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  for(int i=1; i<n; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    G[a].emplace_back(b,d);
    G[b].emplace_back(a,d);
  }
  dfs(1);
  int ix = 1;
  for(int i=1; i<=n; i++) if(dis[i] > dis[ix]) ix = i;
  for(int i=1; i<=n; i++) {
    vis[i] = false;
    dis[i] = 0;
    fat[i] = 0;
  }
  fat[ix] = ix;
  dfs(ix);
  int jx = 1;
  for(int i=1; i<=n; i++) if(dis[i] > dis[jx]) jx = i;
  int t = jx;
  vi X = {t};
  do {
    t = fat[t];
    X.push_back(t);
  }while(X.back() != ix);
  int ct = *max_element(X.begin(), X.end(), [&](int a, int b) {
    return min(dis[jx] - dis[a], dis[a]) < min(dis[jx] - dis[b], dis[b]);
  });
  for(int i=1; i<=n; i++) {
    vis[i] = false;
    dis[i] = 0;
  }
  int a = -1, b = 1e9;
  while(b-a > 1) {
    int m = (a+b)>>1;
    if(check(m,ct,k)) b = m;
    else a = m;
    for(int i=1; i<=n; i++) vis[i] = false;
  }
  cout << b << "\n";
  return 0;
}