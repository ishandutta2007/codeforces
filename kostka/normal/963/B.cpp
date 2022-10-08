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

const int MAXN = 2e5+7;

vi G[MAXN], W[MAXN];
int n, d[MAXN], neigh[MAXN];
bool vis[MAXN], hand[MAXN];

void dfs(int v) {
  vis[v] = true;
  for(auto w : G[v]) {
    if(vis[w]) continue;
    dfs(w);
    if(hand[w]) {
      W[v].push_back(w);
      neigh[v]++;
    }
    else W[w].push_back(v);
  }
  if(neigh[v] % 2 == 0) hand[v] = true;
  else neigh[v]++;
}

void result() {
  vi ret;
  for(int i=1; i<=n; i++) {
    if(d[i] == neigh[i]) {
      ret.push_back(i);
    }
  }
  for(int i=0; i<n; i++) {
    int v = ret[i];
    for(auto w : W[v]) {
      if(--d[w] == neigh[w]) ret.push_back(w);
    }
  }
  assert(n == SZ(ret));
  cout << "YES\n";
  for(auto r : ret) cout << r << "\n";
}

void go(int v) {
  cerr << "GO " << v << "\n";
  dfs(v);
  if(!hand[v]) return;
  result();
  exit(0);
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n;
  for(int i=1; i<=n; i++) {
    int p;
    cin >> p;
    if(p != 0) {
      G[i].push_back(p);
      G[p].push_back(i);
      d[i]++; d[p]++;
    }
  }
  for(int i=1; i<=n; i++) {
    // cerr << "D" << i << " " << d[i] << "\n";
    if(d[i] % 2 == 0) {
      go(i);
      break;
    }
  }
  cout << "NO\n";
  return 0;
}