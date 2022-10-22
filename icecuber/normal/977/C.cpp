#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  sort(a.begin(), a.end());
  int x = k == 0 ? 1 : a[k-1];
  if (k < n && a[k] == x)
    cout << -1 << endl;
  else
    cout << x << endl;
}