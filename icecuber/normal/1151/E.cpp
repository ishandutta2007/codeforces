#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n;
  cin >> n;
  int last;
  cin >> last;
  ll ans = last*(n+1-last);
  for (int i = 1; i < n; i++) {
    int a;
    cin >> a;
    ll x = min(a,last);
    ll y = max(a,last);
    ans += a*(n+1-a)-x*(n+1-y);
    last = a;
  }
  cout << ans << endl;
}