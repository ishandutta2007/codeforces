#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int read() {
  int r = 0;
  string s;
  cin >> s;
  for (char c : s) {
    r = r*2+(c-'0');
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, q;
  cin >> n >> m >> q;
  vector<int> w(n);
  for (int&v : w) cin >> v;
  reverse(w.begin(), w.end());
  vector<int> sum(1<<n);
  for (int i = 0; i < 1<<n; i++) {
    for (int j = 0; j < n; j++) {
      if (i>>j&1) sum[i] += w[j];
    }
  }
  vector<int> c(1<<n);
  for (int i = 0; i < m; i++) {
    c[read()]++;
  }
  vector<vector<int>> ans(1<<n, vector<int>(100+1));
  for (int i = 0; i < 1<<n; i++) {
    for (int j = 0; j < 1<<n; j++) {
      int v = sum[(1<<n)-1]-sum[i^j];
      //cout << bitset<2>(i) << ' ' << bitset<2>(j) << ' ' << v<<endl;
      if (v <= 100)
	ans[i][v] += c[j];
    }
  }
  for (int i = 0; i < q; i++) {
    int x = read(), k;
    cin >> k;
    int r = 0;
    for (int j = 0; j <= k; j++)
      r += ans[x][j];
    cout << r << '\n';
  }
}