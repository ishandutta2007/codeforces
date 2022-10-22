#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[300000], b[300000];

int solve() {
  int n;
  cin >> n;
  int m = 1;
  while (m < n+10) m *= 2;
  vector<int> data(m*2, 0);
  auto add = [&](int i, int v) {
    i += m;
    data[i] += v;
    for (i /= 2; i; i /= 2)
      data[i] = min(data[i*2],data[i*2+1]);
  };
  auto query = [&](int i) {
    int r = 1e9;
    for (i += m; i > 1; i /= 2)
      if (i%2)
	r = min(r, data[i-1]);
    return r;
  };
  map<int,queue<int>> pos;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    pos[a[i]].push(i);
    add(i, a[i]);
  }
  for (int i = 0; i < n; i++)
    cin >> b[i];
  for (int i = 0; i < n; i++) {
    if (pos[b[i]].empty()) return 0;
    int j = pos[b[i]].front();
    if (query(j) < b[i]) return 0;
    pos[b[i]].pop();
    add(j,1e9);
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) cout << (solve() ? "YES" : "NO") << endl;
}