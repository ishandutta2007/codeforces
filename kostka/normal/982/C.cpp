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
int drz[MAXN];
vi G[MAXN];

int dfs(int v) {
  int ans = 0;
  drz[v] = 1;
  for(auto w : G[v]) {
    if(!drz[w]) {
      ans += dfs(w);
      drz[v] += drz[w];
    }
  }
  if(drz[v] % 2 == 0) ans++;
  return ans;
}

int main()
{
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  if(n%2) {
    cout << -1 << "\n";
    return 0;
  }
  for(int i=1; i<n; i++) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  cout << dfs(1)-1 << "\n";
  return 0;
}