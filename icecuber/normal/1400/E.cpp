#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int f(vector<int>&a, int l, int r) {
  vector<array<int,2>> inv;
  int last = -10;
  for (int i = l; i < r; i++) {
    if (a[i] == 0) continue;
    if (i > last+1) {
      inv.push_back({i, i});
    }
    last = i;
    inv.back()[1]++;
  }
  int ans = 0;
  for (auto [s,e] : inv) {
    int mi = 1e9;
    for (int i = s; i < e; i++)
      mi = min(mi, a[i]);
    for (int i = s; i < e; i++)
      a[i] -= mi;
    ans += min(e-s, f(a, s, e)+mi);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  cout << f(a, 0, n) << endl;
}