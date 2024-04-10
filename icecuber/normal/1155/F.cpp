#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[1<<14];
char dp2[1<<14][14];
int adj[14];

int par[1<<14], par2[1<<14][14];
vector<int> vec[1<<14];
int popcount_mem[1<<14];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a] |= 1<<b;
    adj[b] |= 1<<a;
  }
  for (int i = 0; i < 1<<n; i++)
    for (int j = 0; j < n; j++) {
      if (i>>j&1) {
	vec[i].push_back(j);
	popcount_mem[i]++;
      }
    }

  fill_n(dp, (1<<n), 1e9);
  for (int i = 1; i < 1<<n; i++) {
    // if (dp[i] != 1e9) {
    //   for (int j = 0; j < n; j++)
    // 	if (i>>j&1) cout << j+1 << ' ';
    //   cout << endl;
    // }
    if (!(i&(i-1))) //single node
      dp[i] = 0, par[i] = 0;
    if (dp[i] == 1e9) continue;
    fill_n((char*)dp2, 14<<14, 0);
    for (int k = 0; k < n; k++) {
      if (adj[k]&i)
	dp2[1<<k][k] = 1;
    }

    for (int j = 1; j < 1<<n; j++) {
      if (i&j) continue;
      for (int k : vec[j]) {
	int ki = adj[k]&i;
	if (ki && ((j&(j-1)) || (ki&ki-1)) && dp2[j][k]) {
	  int v = dp[i]+popcount_mem[j]+1;
	  if (v < dp[i|j]) {
	    dp[i|j] = v;
	    par[i|j] = i;
	  }
	}
	if (dp2[j][k])
	  for (int l : vec[adj[k]&~(i|j)])
	    dp2[j|1<<l][l] = 1;
      }
    }
  }

  cout << dp[(1<<n)-1] << endl;
  int p = (1<<n)-1;
  while (p&(p-1)) {
    int m = p^par[p];
    fill_n((char*)dp2,14<<n,0);
    for (int k = 0; k < n; k++)
      if (adj[k]&par[p]) {
	dp2[1<<k][k] = 1;
	par2[1<<k][k] = -1;
      }
    int found = -1;
    for (int i = 0; i < 1<<n; i++) {
      if (i&~m) continue;
      for (int k = 0; k < n; k++) {
	if (!(i>>k&1)) continue;
	int i_ = i^1<<k;
	for (int l : vec[i]) {
	  if (dp2[i_][l] && (adj[k]>>l&1)) {
	    dp2[i][k] = 1;
	    par2[i][k] = l;
	    break;
	  }
	}
	if (i == m && (adj[k]&par[p]) && dp2[i][k])
	  found = k;
      }
    }
    assert(found != -1);
    auto match = [&](int m, int c = 1) {
      for (int i = 0; i < n; i++)
	if ((m>>i&1) && !--c) return i;
      return -1;
    };
    int pp = found, mask = m;
    cout << found+1 << ' ' << match(adj[found]&par[p], 1)+1 << endl;
    while (pp != -1) {
      int pa = par2[m][pp];
      if (pa != -1)
	cout << pp+1 << ' ' << pa+1 << endl;
      else
	cout << pp+1 << ' ' << match(adj[pp]&par[p], 1+(pp==found))+1 << endl;
      m ^= 1<<pp;
      pp = pa;
    }
    p = par[p];
  }
}