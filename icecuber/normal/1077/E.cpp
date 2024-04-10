#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[200000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,int> m;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    m[a]++;
  }
  int l = 0;
  for (auto p : m)
    a[l++] = p.second;
  sort(a, a+l);
  reverse(a,a+l);
  ll ans = 0;
  for (int i = 1; i <= 30 && i <= l; i++) {
    ll ma = 1e9;
    for (int j = 0; j < i; j++)
      ma = min(ma, a[j]>>i-1-j);
    ans = max(ans, ma*((1LL<<i)-1));
  }
  cout << ans << endl;
}