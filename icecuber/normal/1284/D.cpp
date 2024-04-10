#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<pair<int,int>> perm(vector<pair<int,int>> a, vector<int> p) {
  auto r = a;
  int n = a.size();
  for (int i = 0; i < n; i++)
    r[i] = a[p[i]];
  return r;
}

const int lods = 20;
struct Sparse {
  vector<vector<int>> data;
  int n;
  Sparse(int n_) {
    n = n_;
    data.resize(lods);
    for (int i = 0; i < lods; i++)
      data[i].resize(n);
  }
  void build() {
    for (int l = 0; l+1 < lods; l++) {
      for (int i = 0; i+(1<<l+1) <= n; i++) {
	data[l+1][i] = max(data[l][i], data[l][i+(1<<l)]);
      }
    }
  }
  int query(int l, int r) {
    /*#warning Slow
    int ret = -2e9;
    for (int i = l; i < r; i++)
      ret = max(ret, data[0][i]);
      return ret;*/

    int w = r-l;
    int lod = 0;
    while (1<<lod+1 < w) lod++;
    return max(data[lod][l], data[lod][r-(1<<lod)]);
  }
};

int check(vector<pair<int,int>> a, vector<pair<int,int>> b) {
  int n = a.size();
  vector<int> p(n);
  for (int i = 0; i < n; i++) p[i] = i;
  sort(p.begin(), p.end(), [&](int i, int j) {return a[i] < a[j];});
  a = perm(a, p);
  b = perm(b, p);
  Sparse mi(n), ma(n);
  for (int i = 0; i < n; i++) mi.data[0][i] =-b[i].second;
  for (int i = 0; i < n; i++) ma.data[0][i] = b[i].first;
  mi.build();
  ma.build();
  for (int i = 0; i < n; i++) {
    int reach = lower_bound(a.begin(), a.end(), make_pair(a[i].second, (int)2e9))-a.begin();
    //cout << -mi.query(i, reach) << ' ' << ma.query(i, reach) << endl;
    if (-mi.query(i, reach) < b[i].first || ma.query(i, reach) > b[i].second) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;
  }
  if (!check(a, b) || !check(b, a)) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}