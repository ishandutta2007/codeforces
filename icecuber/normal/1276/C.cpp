#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,int> count;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    ++count[a];
  }
  vector<pair<int,int>> v;
  for (auto&p : count) v.emplace_back(p.second, p.first);
  sort(v.rbegin(), v.rend());
  ll sum = n;
  int j = 0;
  int m = v.size();
  int maxed = 0;

  int best = 0, bestw, besth;
  for (int h = sum; h >= 1; h--) {
    while (j < m && v[j].first >= h) {
      sum -= v[j].first;
      maxed++;
      j++;
    }
    int w = (sum+maxed*h)/h;
    if (w >= h && w*h > best) {
      best = w*h;
      bestw = w;
      besth = h;
    }
  }

  cout << best << endl;
  cout << besth << ' ' << bestw << endl;

  vector<int> put;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < min(v[i].first, besth); j++)
      put.push_back(v[i].second);
  }

  vector<vector<int>> ans(besth, vector<int>(bestw,-1));
  {
    int x = 0, x0 = 0, y = 0, k = 0;
    for (int i = 0; i < best; i++) {
      ans[y][x] = put[k++];
      x++, y++;
      if (y == besth) x = ++x0, y = 0;
      x %= bestw;
    }
    for (int i = 0; i < besth; i++) {
      for (int j = 0; j < bestw; j++) {
	cout << ans[i][j] << ' ';
      }
      cout << endl;
    }
    /*for (int i = 0; i < besth; i++) {
      set<int> seen;
      for (int j = 0; j < bestw; j++) {
	assert(!seen.count(ans[i][j]));
	seen.insert(ans[i][j]);
      }
    }
    for (int j = 0; j < bestw; j++) {
      set<int> seen;
      for (int i = 0; i < besth; i++) {
	assert(!seen.count(ans[i][j]));
	seen.insert(ans[i][j]);
      }
      }*/
  }
}