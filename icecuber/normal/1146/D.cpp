#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dist[300000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll m, a, b;
  cin >> m >> a >> b;
  ll m0 = m;
  m = min(m, a+b);
  fill_n(dist, m+1, 1e9);
  dist[0] = 0;
  priority_queue<pair<int,int>> pq;
  pq.push({0,0});
  while (pq.size()) {
    int p = pq.top().second;
    int d =-pq.top().first;
    pq.pop();
    if (d > dist[p]) continue;
    for (int k : {a,-b}) {
      int d_ = max(d, p+k);
      if (p+k >= 0 && p+k <= m && d_ < dist[p+k]) {
	dist[p+k] = d_;
	pq.push({-d_,p+k});
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i <= m; i++) {
    //assert(m < a+b || (dist[i]==1e9)==!!(i%g));
    ans += max(0ll,m+1-dist[i]);
  }
  {
    ll g = __gcd(a,b);
    ans += (m0/g+1)*(2*(m0+1)-m0/g*g)/2-(m/g+1)*(2*(m+1)-m/g*g)/2;
  }
  cout << ans << endl;
}