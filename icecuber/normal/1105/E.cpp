#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int adj[40][40];
int dp[1<<20];
int maska[1<<20], maskb[1<<20], maskba[1<<20];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q, m;
  cin >> q >> m;
  int ids = 0;
  map<string, int> id;
  set<int> s;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      for (int i : s)
	for (int j : s)
	  if (i != j) adj[i][j] = 1;
      s.clear();
    } else {
      string name;
      cin >> name;
      if (!id.count(name)) id[name] = ids++;
      s.insert(id[name]);
    }
  }
  for (int i : s)
    for (int j : s)
      if (i != j) adj[i][j] = 1;

  int a = min(m,20), b = m-a;
  for (int i = 0; i < a; i++)
    for (int j = 0; j < a; j++)
      if (adj[i][j]) maska[i] |= 1<<j;
  for (int i = 0; i < b; i++)
    for (int j = 0; j < b; j++)
      if (adj[a+i][a+j]) maskb[i] |= 1<<j;

  for (int i = 0; i < b; i++)
    for (int j = 0; j < a; j++)
      if (adj[a+i][j]) maskba[i] |= 1<<j;

  for (int i = 0; i < 1<<a; i++) {
    dp[i] = 0;
    int allgood = 1, pop = 0;
    for (int j = 0; j < a; j++) {
      if (i>>j&1) {
	if (maska[j]&i) allgood = 0;
	pop++;
	dp[i] = max(dp[i], dp[i^1<<j]);
      }
    }
    if (allgood) dp[i] = pop;
  }
  int ans = 0;
  for (int i = 0; i < 1<<b; i++) {
    int ia = 0, allgood = 1, pop = 0;
    for (int j = 0; j < b; j++)
      if (i>>j&1) {
	ia |= maskba[j];
	pop++;
	if (maskb[j]&i) allgood = 0;
      }
    if (allgood)
      ans = max(ans, dp[(1<<a)-1^ia]+pop);
  }
  cout << ans << endl;
}