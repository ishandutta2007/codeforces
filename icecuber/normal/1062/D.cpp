#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[100001];
int done[100001];

ll dfs(int p) {
  if (done[p]++) return 0;
  ll ans = 0;
  for (int i : node[p]) {
    ans += max(i/p, p/i);
    ans += dfs(i);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 2; i <= n; i++) {
    for (int j = 2*i; j <= n; j += i) {
      node[i].push_back(j);
      node[j].push_back(i);
    }
  }
  ll ans = 0;
  for (int i = 2; i <= n; i++) {
    ans = max(ans, dfs(i));
  }
  cout << ans*2 << endl;
}