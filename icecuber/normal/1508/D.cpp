#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;

  vector<array<ll,2>> pos(n);
  vector<int> p(n);
  array<ll,2> base = {(int)1e9,(int)1e9};
  vector<int> order;
  for (int i = 0; i < n; i++) {
    cin >> pos[i][0] >> pos[i][1] >> p[i];
    p[i]--;
    if (p[i] != i) {
      order.push_back(i);
      base = min(base, pos[i]);
    }
  }
  if (order.empty()) {
    cout << 0 << endl;
    return 0;
  }
  sort(order.begin(), order.end(), [&](int ai, int bi) {
      array<ll,2> a = pos[ai], b = pos[bi];
      a[0] -= base[0];
      a[1] -= base[1];
      b[0] -= base[0];
      b[1] -= base[1];
      ll cross = a[0]*b[1]-a[1]*b[0];
      if (cross) return cross > 0;
      else return a[0]*a[0]+a[1]*a[1] < b[0]*b[0]+b[1]*b[1];
      });

  mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count());

  int m = order.size();
  vector<int> path;
  int tries = 0;
  while (1) {
    auto cp = p;
    vector<int> a;
    for (int i = 1; i+1 < m; i++) a.push_back(i);
    shuffle(a.begin(), a.end(), mrand);
    while (mrand()%2 && a.size()) a.pop_back();
    for (int i : a) {
      swap(cp[order[i]],cp[order[i+1]]);
    }
    int l = 0, x = order[0];
    do {
      x = cp[x];
      l++;
    } while (x != order[0]);
    tries++;
    if (l == m) {
      path = a;
      break;
    }
  }

  vector<array<int,2>> ans;
  for (int i : path) {
    ans.push_back({order[i], order[i+1]});
    swap(p[order[i]],p[order[i+1]]);
  }

  while (p[order[0]] != order[0]) {
    ans.push_back({order[0], p[order[0]]});
    swap(p[order[0]], p[p[order[0]]]);
  }
  cout << ans.size() << endl;
  for (auto [a,b] : ans) cout << a+1 << ' ' << b+1 << endl;
  
  for (int i = 0; i < n; i++)
    assert(p[i] == i);

  return 0;

  /*
  if (0) {
  int n = 1000;
  vector<int> p(n);
  for (int i = 0; i < n; i++) p[i] = i;

  while (1) {
    random_shuffle(p.begin(), p.end());
    if (p[0] == 0) continue;

    int tries = 0;
    while (1) {
      auto cp = p;
      vector<int> a;
      for (int i = 1; i+1 < n; i++) a.push_back(i);
      random_shuffle(a.begin(), a.end());
      while (rand()%2 && a.size()) a.pop_back();
      for (int i : a) {
        swap(cp[i],cp[i+1]);
      }
      int l = 0, x = 0;
      do {
        x = cp[x];
        l++;
      } while (x != 0);
      tries++;
      if (l == n) break;
    }

    cout << tries << endl;
  }
}*/
}