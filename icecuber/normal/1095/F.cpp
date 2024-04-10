#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<pair<ll,int>> node[200000];
int done[200000];
ll a[200000];
int main() {
  ios::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  set<pair<ll,int>> in, out;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    out.insert({a[i],i});
  }
  while (m--) {
    ll a, b, c;
    cin >> a >> b >> c;
    a--,b--;
    node[a].push_back({-c,b});
    node[b].push_back({-c,a});
  }
  node[0].push_back({-(1LL<<62), 0});
  ll ans = 0;
  priority_queue<pair<ll,int>> pq;
  pq.push({0,0});
  while (out.size()) {
    int p = pq.top().second;
    ll q = -pq.top().first;
    if (in.size() && out.size() && in.begin()->first + out.begin()->first < q) {
      q = in.begin()->first + out.begin()->first;
      p = out.begin()->second;
      goto perform;
    }
    pq.pop();
  perform:
    if (done[p]++) continue;
    ans += q;
    out.erase({a[p],p});
    in.insert({a[p],p});
    for (auto e : node[p]) pq.push(e);
  }
  cout << ans << endl;
}