#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<pair<int,int>> v;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.emplace_back(a,i);
  }
  sort(v.begin(), v.end());
  int start = 1;
  while (start < n && v[start].second >= v[start-1].second) start++;
  int end = n-1;
  while (end > 0 && v[end-1].second <= v[end].second) end--;

  //for (auto p : v) cout << p.first << ' ' << p.second << endl;
  int starti = start == n ? m : v[start].first;

  ll ans = 0;
  int li = 0, ri = end;
  for (int l = 1; l <= starti; l++) {
    while (li < start && v[li].first < l) li++;
    int ly = li == 0 ? -1 : v[li-1].second;
    while (ri < n && v[ri].second < ly) ri++;
    int r = max(l, ri == 0 ? l : v[ri-1].first);
    //cout << l << ' ' << li << ' ' << ly << ' ' << ri << ' ' << r << endl;
    ans += m+1-r;
  }
  cout << ans << endl;
}