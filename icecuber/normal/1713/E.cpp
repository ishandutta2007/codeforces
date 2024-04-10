#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (auto&v : a)
      for (int&x : v) cin >> x;
    vector<array<int,3>> par(n);
    for (int i = 0; i < n; i++) par[i] = {i,1,0};
    auto find = [&](int p) {
      int flip = 0;
      while (p != par[p][0]) {
        flip ^= par[p][2];
        p = par[p][0];
      }
      return make_pair(p,flip);
    };
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        if (a[i][j] != a[j][i]) {
          auto [x,fx] = find(i);
          auto [y,fy] = find(j);
          if (x != y) {
            if (par[x][1] < par[y][1]) swap(x,y);
            par[y][0] = par[x][0];
            par[y][2] = (a[i][j] > a[j][i]) ^ fx ^ fy;
            par[x][1] += par[y][1];
          }
        }
      }
    }
    vector<array<int,2>> order;
    for (int i = 0; i < n; i++) {
      order.push_back({par[i][1], i});
    }
    sort(order.rbegin(), order.rend());
    vector<int> flip(n);
    for (auto [sz,i] : order) {
      if (par[i][0] == i) continue;
      flip[i] = flip[par[i][0]]^par[i][2];
    }
    for (int i = 0; i < n; i++) {
      if (flip[i]) {
        for (int j = 0; j < n; j++) {
          swap(a[i][j], a[j][i]);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        cout << a[i][j] << ' ';
      cout << '\n';
    }
  }
}