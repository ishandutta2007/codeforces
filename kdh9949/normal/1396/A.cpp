#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) v.begin(),v.end()

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vll a(n + 1);
  for(int i = 1; i <= n; i++) cin >> a[i];

  if(n == 1) {
    cout << "1 1\n";
    cout << -a[1] << '\n';
    cout << "1 1\n0\n1 1\n0\n";
    return 0;
  }

  cout << 1 << ' ' << (n - 1) << '\n';
  for(int i = 1; i <= n - 1; i++) {
    ll t = ll(n - 1) * (a[i] % n);
    cout << t << " \n"[i == n - 1];
    a[i] += t;
  }

  cout << n << ' ' << n << '\n';
  cout << -a[n] << '\n';
  a[n] = 0;

  cout << 1 << ' ' << n << '\n';
  for(int i = 1; i <= n; i++) cout << -a[i] << " \n"[i == n];

  return 0;
}