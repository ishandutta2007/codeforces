#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    vector<int> v(k);
    for (int j = 0; j < k; j++) {
      cin >> v[j];
    }
    int good = 0;
    for (int j = 1; j < k; j++)
      if (v[j-1] < v[j]) good = 1;
    a[i] = v[0];
    b[i] = v[k-1];
    if (good) {
      a[i] = 1e9;
      b[i] =-1e9;
    }
  }
  sort(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ans += n-(upper_bound(a.begin(), a.end(), b[i])-a.begin());
  }
  cout << ans << endl;
}