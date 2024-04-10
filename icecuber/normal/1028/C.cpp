#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ax[200000], ay[200000], bx[200000], by[200000];

vector<int> solve(int*s, int*e, int n) {
  vector<pair<int, int>> event;
  for (int i = 0; i < n; i++) {
    event.push_back({s[i],-1});
    event.push_back({e[i], 1});
  }
  sort(event.begin(), event.end());
  int cover = 0;
  vector<int> ret;
  for (auto p : event) {
    cover -= p.second;
    if (cover >= n-1)
      ret.push_back(p.first);
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> ax[i] >> ay[i] >> bx[i] >> by[i];
  vector<int> xv = solve(ax, bx, n);
  vector<int> yv = solve(ay, by, n);
  for (int x : xv)
    for (int y : yv) {
      int in = 0;
      for (int i = 0; i < n; i++) {
	in += (x >= ax[i] && x <= bx[i] && y >= ay[i] && y <= by[i]);
      }
      if (in >= n-1) {
	cout << x << ' ' << y << endl;
	return 0;
      }
    }
}