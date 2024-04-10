#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int solve(vector<pair<int,int>> a, int m) {
  sort(a.rbegin(), a.rend());
  int n = a.size();
  int j = n-1;
  int suf = -1e9, ans = -1e9;
  for (int i = 0; i < j; i++) {
    while (j > i && a[i].first + a[j].first <= m) {
      suf = max(suf, a[j--].second);
      ans = max(ans, suf+a[j].second);
    }
    ans = max(ans, suf+a[i].second);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, c, d;
  cin >> n >> c >> d;
  int bc = -1e9, bd = -1e9;
  vector<pair<int,int>> C, D;
  for (int i = 0; i < n; i++) {
    int b, p;
    char type;
    cin >> b >> p >> type;
    if (type == 'C') {
      if (p <= c) {
	bc = max(bc, b);
	C.emplace_back(p, b);
      }
    } else {
      if (p <= d) {
	bd = max(bd, b);
	D.emplace_back(p, b);
      }
    }
  }
  cout << max({bc+bd, solve(C, c), solve(D, d), 0}) << endl;
}