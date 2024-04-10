#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int h[200000];
vector<int> node[200000];
int done[200000];
vector<int> topo;
void dfs(int p) {
  if (done[p]++) return;
  for (int i : node[p]) {
    dfs(i);
  }
  topo.push_back(p);
}
int grundy[200000];
int grundy2[200000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> h[i];
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
  }
  for (int i = 0; i < n; i++)
    dfs(i);

  for (int p : topo) {
    vector<int> v;
    for (int i : node[p])
      v.push_back(grundy[i]);
    sort(v.begin(), v.end());
    int x = 0;
    while (binary_search(v.begin(), v.end(), x)) x++;
    grundy[p] = x;
    grundy2[x] ^= h[p];
  }
  int high = 0;
  ll lose = 1;
  for (int i = 0; i < n; i++)
    if (grundy2[i]) {
      lose = 0;
      high = max(high, i);
    }
  if (lose) {
    cout << "LOSE" << endl;
    return 0;
  }
  for (int p = 0; p < n; p++) {
    int x = grundy[p];
    if (x == high && (h[p]>>31-__builtin_clz(grundy2[x])&1)) {
      assert(grundy2[x]>>31-__builtin_clz(grundy2[x])&1);
      h[p] ^= grundy2[x];
      grundy2[x] = 0;
      for (int i : node[p]) {
	h[i] ^= grundy2[grundy[i]];
	grundy2[grundy[i]] = 0;
      }
      cout << "WIN" << endl;
      for (int i = 0; i < n; i++)
	cout << h[i] << ' ';
      cout << endl;
      return 0;
    }
  }
}