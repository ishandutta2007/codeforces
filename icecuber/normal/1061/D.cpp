#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef long long ll;
ll mod = 1e9+7;

pair<int, int> e[100000];
int main() {
  ios::sync_with_stdio(0);
  ll n, a, b;
  cin >> n >> b >> a;
  b -= a;
  for (int i = 0; i < n; i++) {
    cin >> e[i].x >> e[i].y;
    e[i].y++;
  }
  sort(e, e+n);
  ll ans = 0;
  multiset<int> avail;
  for (int i = 0; i < n; i++) {
    int start = e[i].x, end = e[i].y;
    auto it = avail.upper_bound(start);
    if (it != avail.begin()) {
      --it;
      ll c1 = (end-*it)*a, c2 = (end-start)*a+b;
      ans = (ans+min(c1,c2))%mod;
      avail.erase(it);
    } else {
      ll cost = (end-start)*a+b;
      ans = (ans+cost)%mod;
    }
    avail.insert(end);
  }
  cout << ans << endl;
}