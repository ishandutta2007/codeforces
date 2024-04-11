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

const int MAXN = 300007;
vi G[MAXN];
bool odw[MAXN], zawy[MAXN];
int pod[MAXN];

int n, x, y;

void dfs(int v) {
  if(v == y) zawy[v] = true;
  pod[v] = 1;
  odw[v] = true;
  for(auto w : G[v]) {
    if(!odw[w]) {
      dfs(w);
      pod[v] += pod[w];
      if(zawy[w]) zawy[v] = true;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin >> n >> x >> y;
  for(int i=1; i<n; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  dfs(x);
  int lew = 1, pra = 0;
  for(auto s : G[x]) {
    if(!zawy[s]) lew += pod[s];
  }
  pra = pod[y];
  long long res = 1LL*n*n - n - 1LL*lew*pra;
  cout << res << "\n";
  return 0;
}