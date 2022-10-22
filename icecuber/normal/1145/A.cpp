#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&i : a) cin >> i;
  for (int k = 4; k >= 0; k--) {
    if ((1<<k) > n) continue;
    for (int i = 0; i < n; i += (1<<k)) {
      vector<int> b, c;
      for (int j = i; j < i+(1<<k); j++)
	b.push_back(a[j]);
      c = b;
      sort(b.begin(), b.end());
      if (b == c) {
	cout << (1<<k) << endl;
	return 0;
      }
    }
  }
}