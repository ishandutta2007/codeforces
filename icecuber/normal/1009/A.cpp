#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> c(n), b(m);
  for (int&v : c) cin >> v;
  for (int&v : b) cin >> v;
  int j = 0;
  for (int i = 0; i < n && j < m; i++) {
    if (b[j] >= c[i]) j++;
  }
  cout << j << endl;
}