#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  sort(a.begin(), a.end());
  if (a[n-3]+a[n-2] <= a[n-1]) {
    cout << "NO" << endl;
    return 0;
  }
  swap(a[n-2], a[n-1]);
  cout << "YES" << endl;
  for (int v : a) cout << v << ' ';
  cout << endl;
}