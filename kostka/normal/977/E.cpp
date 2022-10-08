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
vi G[MAXN];
bool odw[MAXN];

int wierz, kraw, good_wierz;

void dfs(int v) {
  odw[v] = true;
  wierz++;
  kraw += G[v].size();
  if(G[v].size() == 2) good_wierz++;
  for(auto w : G[v]) {
    if(!odw[w]) dfs(w);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int ile = 0;
  for(int i=1; i<=n; i++) {
    if(odw[i]) continue;
    wierz = 0;
    kraw = 0;
    good_wierz = 0;
    dfs(i);
    if(2 * wierz == kraw and wierz == good_wierz) {
      ile++;
    }
  }
  cout << ile << "\n";
  return 0;
}