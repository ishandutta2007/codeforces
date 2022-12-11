#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
using ll = unsigned long long;
int Set(ll x) {
  int st = 0;
  while(x) {
    st |= 1 << (x % 10);
    x /= 10;
  }
  return st;
}
int main() {
  int n;
  ll x, l, r;
  cin >> n >> x;
  l = (ll)pow(10.0, n - 1);
  r = l * 10;
  unordered_map<ll, int> dis;
  dis[x] = 0;
  queue<ll> q; q.push(x);
  while(q.size()) {
    ll z = q.front();
    int d = dis[z], s = Set(z);
    q.pop();
    if(l <= z && z < r) {
      cout << d << '\n';
      return 0;
    }
    ll z0 = z;
    for(int i = 2; i < 10; i ++) {
      z0 += z;
      if(z > (double)r / i) break ;
      if(s >> i & 1 && !dis.count(z0)) {
        dis[z0] = d + 1;
        q.push(z0);
      }
    }
  }
  cout << -1 << '\n';
  return 0;
}