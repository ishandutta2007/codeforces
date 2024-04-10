#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int base = 0;
    vector<int> v;
    for (int i = 0; i+1 < n; i++) {
      if (a[i] == -1 && a[i+1] != -1) v.push_back(a[i+1]);
      if (a[i] != -1 && a[i+1] == -1) v.push_back(a[i]);
      if (a[i] != -1 && a[i+1] != -1)
	base = max(base, abs(a[i]-a[i+1]));
    }
    if (v.empty()) {
      cout << 0 << ' ' << 0 << endl;
    } else {
      sort(v.begin(), v.end());
      int k = (v.back()+v[0])/2;
      cout << max({v.back()-k, k-v[0], base}) << ' ' << k << endl;
    }
  }
}