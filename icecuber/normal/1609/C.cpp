#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isprime(int n) {
  for (int i = 2; i*i <= n; i++) {
    if (n%i == 0) return 0;
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int&v : a) {
      cin >> v;
      if (v == 1) v = 0;
      else if (isprime(v)) v = 1;
      else v = 2;
    }
    ll ans = 0;
    for (int s = 0; s < d; s++) {
      int acc = 0;
      map<int,int> cnt;
      for (int i = s; i < n; i += d) {
        cnt[acc]++;
        acc += a[i];
        ans += cnt[acc-1];
        ans -= a[i] == 1;
      }
    }
    cout << ans << endl;
  }
}