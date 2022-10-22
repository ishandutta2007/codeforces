#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, k;
  cin >> n >> k;
  if (k*(k+1)/2 > n) {
    cout << "NO" << endl;
    return 0;
  }
  vector<int> ans;
  ll mi = 1, ma = n;
  for (int i = 0; i < k; i++) {
    ll v = min((n-(k-i)*(k-1-i)/2)/(k-i), ma);
    n -= v;
    ans.push_back(v);
    mi = v+1;
    ma = v*2;
  }
  if (!n) {
    cout << "YES" << endl;
    for (int i : ans) cout << i << ' ';
    cout << endl;
  } else cout << "NO" << endl;
}