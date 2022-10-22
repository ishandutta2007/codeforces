#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());

vector<ll> rnd, acc, acc2;
int check(int i, int n) {
  if (i < 0) return 0;
  return (acc[i+n]^acc[i]) == acc2[n];
}
ll solve(vector<int> a) {
  int n = a.size();
  rnd.resize(n+1,0), acc.resize(n+1,0), acc2.resize(n+1,0);
  for (int i = 1; i <= n; i++)
    rnd[i] = mrand();
  for (int i = 1; i <= n; i++) {
    acc[i] = acc[i-1]^rnd[a[i-1]];
    acc2[i] = acc2[i-1]^rnd[i];
  }

  ll r = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != 1) continue;
    int ma = 1;
    for (int j = i+1; a[j] != 1 && j < n; j++) {
      ma = max(ma, a[j]);
      r += check(j+1-ma, ma);
    }
  }
  return r;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  ll ans = count(a.begin(), a.end(), 1);
  ans += solve(a);
  reverse(a.begin(), a.end());
  ans += solve(a);
  cout << ans << endl;
}