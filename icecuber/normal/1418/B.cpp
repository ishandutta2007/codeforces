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
    vector<int> a(n), l(n);
    for (int& v : a) cin >> v;
    for (int& v : l) cin >> v;
    vector<int> b;
    for (int i = 0; i < n; i++) {
      if (!l[i]) b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < n; i++) {
      if (!l[i]) a[i] = b.back(), b.pop_back();
    }
    for (int v : a) cout << v << ' ';
    cout << endl;
  }
}