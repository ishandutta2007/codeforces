#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int>> node[80];

int mem[80][80][80][80];

int f(int l, int r, int p, int left) {
  if (left == 0) return 0;
  int&memo = mem[l][r][p][left];
  if (!memo) {
    int ans = 1e9;

    for (auto i : node[p]) {
      int j = i.first;
      if (j >= l && j <= r) {
	int nl = l, nr = r;
	if (j < p) nr = p-1;
	else nl = p+1;
	ans = min(ans, i.second+f(nl,nr, j, left-1));
      }
    }
    memo = ans+1;
  }
  return memo-1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k, m;
  cin >> n >> k >> m;
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--, b--;
    if (a == b) continue;
    node[a].push_back({b,c});
  }
  for (int i = 0; i < n; i++)
    sort(node[i].begin(), node[i].end());

  int ans = 1e9;
  for (int i = 0; i < n; i++) {
    ans = min(ans, f(0,n-1,i,k-1));
  }
  if (ans == 1e9) ans = -1;
  cout << ans << endl;
}