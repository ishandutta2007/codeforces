#include <bits/stdc++.h>

#include <algorithm>

using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
void ast(ll x, ll l, ll r) { assert(x >= l && x <= r); }
const int N = 505;
int m, k, a[N], ans[1005][1005];
vector<pair<int, int> > vc;
vector<pair<int, int> > red, blue, yellow;
void Set(pair<int, int> x, int val) { ans[x.first][x.second] = val; }
bool judge(int n) {
  if (m > n * n - (n / 2) * (n / 2)) return false;
  if (vc[0].first > n * (n - n / 2)) return false;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) ans[i][j] = 0;
  red.clear();
  blue.clear();
  yellow.clear();
  for (int i = 1; i <= n; i += 2)
    for (int j = 1; j <= n; j += 2) blue.push_back(mp(i, j));
  for (int i = 1; i <= n; i += 2)
    for (int j = 2; j <= n; j += 2) yellow.push_back(mp(i, j));
  for (int i = 2; i <= n; i += 2)
    for (int j = 1; j <= n; j += 2) red.push_back(mp(i, j));
  for (int i = 0; i < vc.size(); i++) {
    if (red.size()) {
      if (vc[i].first <= red.size()) {
        for (int j = 1; j <= vc[i].first; j++)
          Set(red.back(), vc[i].second), red.pop_back();
      } else {
        int t = vc[i].first - red.size();
        while (red.size()) Set(red.back(), vc[i].second), red.pop_back();
        while (t--) Set(blue.back(), vc[i].second), blue.pop_back();
      }
    } else if (yellow.size()) {
      if (vc[i].first <= yellow.size()) {
        for (int j = 1; j <= vc[i].first; j++)
          Set(yellow.back(), vc[i].second), yellow.pop_back();
      } else {
        int t = vc[i].first - yellow.size();
        while (yellow.size())
          Set(yellow.back(), vc[i].second), yellow.pop_back();
        while (t--) Set(blue.back(), vc[i].second), blue.pop_back();
      }
    } else {
      for (int j = 1; j <= vc[i].first; j++)
        Set(blue.back(), vc[i].second), blue.pop_back();
    }
  }
  return true;
}
int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    vc.clear();
    scanf("%d%d", &m, &k);
    for (int i = 1; i <= k; i++) {
      int x;
      scanf("%d", &x);
      if (x) vc.push_back(mp(x, i));
    }
    sort(vc.begin(), vc.end());
    reverse(vc.begin(), vc.end());
    int l = 1, r = sqrt(m * 2) + 10;
    while (l < r) {
      int mid = (l + r) >> 1;
      if (judge(mid))
        r = mid;
      else
        l = mid + 1;
    }
    judge(r);
    printf("%d\n", r);
    for (int i = 1; i <= r; i++)
      for (int j = 1; j <= r; j++) printf(j == r ? "%d\n" : "%d ", ans[i][j]);
  }
}