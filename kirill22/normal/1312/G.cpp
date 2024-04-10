#include <set>
#include <deque>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
 
using namespace std;
 
const int MAXN = 1000001;
 
int go[MAXN][26];
bool term[MAXN];
int les[MAXN];
 
int dp[MAXN];
 
int dfs1(int v, int cnt){
  cnt += term[v];
  les[v] = cnt;
  for (int j = 0; j < 26; ++j){
    if (go[v][j] != -1)
      cnt += dfs1(go[v][j], cnt);
  }
  return cnt - les[v] + term[v];
}
 
void dfs(int v, int p, int x){
  if (term[v]) {
    dp[v] = min(dp[p] + 1, x + les[v]);
  } else
    dp[v] = dp[p] + 1;
  x = min(x, dp[v] - les[v] + term[v]);
  //cout << v << ' ' << dp[v] << ' ' << les[v] << '\n';
  for (int j = 0; j < 26; ++j){
    if (go[v][j] != -1)
      dfs(go[v][j], v, x);
  }
}
 
int main(){
#ifdef DEBUG
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
#endif
 
  int n;
  cin >> n;
  for (int i = 0; i <= n; ++i)
    fill(go[i], go[i] + 26, -1);
  for (int i = 0; i < n; ++i){
    int p;
    char c;
    cin >> p >> c;
    go[p][c - 'a'] = i + 1;
  }
  int m;
  cin >> m;
  vector<int> ind(m);
  for (int i = 0; i < m; ++i)
    cin >> ind[i];
  for (int i = 0; i < m; ++i)
    term[ind[i]] = true;
  dfs1(0, 0);
  for (int j = 0; j < 26; ++j){
    if (go[0][j] != -1)
      dfs(go[0][j], 0, 0);
  }
  for (int i: ind)
    cout << dp[i] << ' ';
  cout << '\n';
  return 0;
}