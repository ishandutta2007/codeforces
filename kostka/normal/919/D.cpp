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
vi G[MAXN], O[MAXN];
int in[MAXN];
int dp[MAXN];

int main()
{
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  string val;
  cin >> val;
  while(m--) {
    int a, b;
    cin >> a >> b;
    G[a].push_back(b);
    O[b].push_back(a);
    in[b]++;
  }
  vector <int> V;
  for(int i=1; i<=n; i++) {
    if(in[i] == 0) V.push_back(i);
  }
  for(int i=0; i<SZ(V); i++) {
    int v = V[i];
    for(auto w : G[v]) {
      in[w]--;
      if(in[w] == 0) V.push_back(w);
    }
  }
  if(SZ(V) != n) {
    cout << -1 << "\n";
    return 0;
  }
  int res = 0;
  for(char x = 'a'; x <= 'z'; x++) {
    for(int i=1; i<=n; i++) dp[i] = ((val[i-1] == x) ? 1 : 0);
    for(auto v : V) {
      int akt = 0;
      for(auto w : O[v]) {
        akt = max(akt, dp[w]);
      }
      dp[v] += akt;
    }
    for(int i=1; i<=n; i++) res = max(res, dp[i]);
  }
  cout << res << "\n";
  return 0;
}