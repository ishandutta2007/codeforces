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

const int MAXN = 1e5+7;

vi G[MAXN];
int lvl[MAXN];

void dfs(int v, int p = 0) {
  lvl[p]++;
  for(auto w : G[v]) {
    dfs(w, p+1);
  }
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  for(int i=2; i<=n; i++) {
    int x;
    cin >> x;
    G[x].push_back(i);
  }
  dfs(1);
  int ret = 0;
  for(int i=0; i<=n; i++) {
    ret += lvl[i] & 1;
  }
  cout << ret << "\n";
  return 0;
}