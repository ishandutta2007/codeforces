#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;

  multiset<int> left;
  for (int i = 0; i < a.back(); i++)
    left.insert(i);
  for (int i = a.back(); i < n; i++)
    left.insert(1e6);
  vector<int> ans(n, -1);
  for (int i = 0; i < n; i++) {
    if (i && a[i] != a[i-1]) {
      left.erase(a[i-1]);
      ans[i] = a[i-1];
    }
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] == -1) {
      ans[i] = *left.begin();
      left.erase(left.begin());
    }
  }
  for (int v : ans) cout << v << ' ';
  cout << endl;
}