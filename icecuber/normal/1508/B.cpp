#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mem[100];
ll f(int n) {
  // return 1ll<<max(n-1,0)
  if (n >= 100) return 2e18;
  if (n == 0) return 1;
  
  ll&memo = mem[n];
  if (memo) return memo;

  for (int i = 0; i < n; i++) {
    memo += f(i);
    if (memo > 2e18) break;
  }
  memo = min(memo, ll(2e18));
  return memo;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  //for (int i = 0; i < 100; i++) cout << f(i) << ' ';
  //cout << endl;
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    if (f(n) < k) {
      cout << -1 << endl;
      continue;
    }
    vector<int> ans;
    for (int i = 0; i < n; i++) {
      int j = i;
      while (k > f(n-1-j)) {
        k -= f(n-1-j);
        j++;
      }
      for (int l = j; l >= i; l--) {
        ans.push_back(l+1);
      }
      i = j;
    }
    for (int v : ans) cout << v << ' ';
    cout << endl;
  }
}