#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

ll mod = 1e9+7;

const int M = 500010;
ll data[M];
ll sum(int i) {
  ll ans = 0;
  for (; i; i -= i&-i) {
    ans += data[i];
    if (ans >= mod) ans -= mod;
  }
  return ans;
}
void add(int i, ll v) {
  v %= mod;
  for (; i < M; i += i&-i) {
    data[i] += v;
    if (data[i] >= mod) data[i] -= mod;
  }
}

pair<ll,ll> a_[500000], a[500000], b[500000];
ll solve(int n, int second = 0) {
  for (int i = 0; i < n; i++) {
    a[i].x = a_[i].x;
    a[i].y = i;
  }
  sort(a, a+n);
  for (int i = 0; i < n; i++) {
    b[a[i].y].x = a[i].x;
    b[a[i].y].y = i+1;
  }
  fill_n(data, M, 0);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (second)
      add(b[i].y, i+1);
    (ans += b[i].x*sum(b[i].y)%mod*(n-i)) %= mod;
    if (!second)
      add(b[i].y, i+1);
  }
  return ans;
}

ll solve2(int n) {
  ll ans = 0;
  for (int l = 0; l < n; l++)
    for (int r = l; r < n; r++)
      ans += max(a_[l].x,a_[r].x)*(l+1)*(n-r);
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> a_[i].x;
  ll ans = solve(n);
  reverse(a_, a_+n);
  ans += solve(n,1);
  cout << ans%mod << endl;
}