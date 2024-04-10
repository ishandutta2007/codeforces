#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    map<int,int> cnt;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      cnt[v]++;
    }
    set<array<int,2>> bad;
    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      bad.insert({x,y});
    }
    map<int,vector<int>> group;
    for (auto [v,c] : cnt) {
      group[c].push_back(v);
    }
    for (auto&[c,g] : group) sort(g.rbegin(), g.rend());

    ll ans = 0;
    for (auto [cx,gx] : group) {
      for (auto [cy,gy] : group) {
        if (cx < cy) continue;
        set<array<int,2>> added;
        priority_queue<array<int,3>> pq;
        pq.push({gx[0]+gy[0], 0, 0});
        added.insert({0,0});
        while (pq.size()) {
          auto [s,xi,yi] = pq.top();
          pq.pop();
          int x = gx[xi], y = gy[yi];
          if (x > y) swap(x,y);
          if (x != y && !bad.count({x,y})) {
            ans = max(ans, (ll)(x+y)*(cx+cy));
            break;
          }
          if (xi+1 < (int)gx.size() && !added.count({xi+1,yi})) {
            pq.push({gx[xi+1]+gy[yi], xi+1, yi});
            added.insert({xi+1,yi});
          }
          if (yi+1 < (int)gy.size() && !added.count({xi,yi+1})) {
            pq.push({gx[xi]+gy[yi+1], xi, yi+1});
            added.insert({xi,yi+1});
          }
        }
      }
    }
    cout << ans << endl;
  }
}