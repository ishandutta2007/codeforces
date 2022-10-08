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

const int MAXN = 200007;
vi G[MAXN];
int pre[MAXN], post[MAXN], t, odw[2*MAXN];

void dfs(int v) {
  pre[v] = ++t;
  odw[t] = v;
  for(auto w : G[v]) if(!pre[w]) dfs(w);
  post[v] = t;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, q;
  cin >> n >> q;
  for(int i=2; i<=n; i++) {
    int j;
    cin >> j;
    G[i].push_back(j);
    G[j].push_back(i);
  }
  for(int i=1; i<=n; i++) sort(G[i].begin(), G[i].end());
  dfs(1);
  while(q--) {
    int u, k;
    cin >> u >> k;
    int pos = odw[pre[u]+k-1];
    if(pos == 0 or not(pre[u] <= pre[pos] and post[pos] <= post[u])) pos = -1;
    cout << pos << "\n";
  }
  return 0;
}