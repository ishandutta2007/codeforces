#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<ll,int>> node[100000];
ll special[100000], done[100000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  int x;
  for (int i = 0; i < k; i++) {
    cin >> x;
    special[--x] = 1;
  }
  while (m--) {
    int a, b, c;
    cin >> a >> b >> c;
    a--,b--;
    node[a].push_back({-c,b});
    node[b].push_back({-c,a});
  }
  int k2 = k;
  priority_queue<pair<ll,int>> pq;
  pq.push({0,x});
  ll ans = 0;
  while (pq.size()) {
    int p = pq.top().second;
    ll d = -pq.top().first;
    pq.pop();
    if (done[p]++) continue;
    ans = max(ans, d);
    k2 -= special[p];
    if (!k2) break;
    for (auto e : node[p]) pq.push(e);
  }
  for (int i = 0; i < k; i++)
    cout << ans << ' ';
  cout << endl;
}