#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll ans = 0;
void dq(vector<pair<int,int>>&p) {
  if (p.size() <= 1) return;
  sort(p.begin(), p.end());
  int mid = p.size()/2;
  vector<pair<int,int>> a, b;
  for (int i = 0; i < p.size(); i++)
    (i < mid ? a : b).push_back(p[i]);
  for (int k : {0,1}) {
    auto&v = k ? a : b;
    sort(v.begin(), v.end(), [](pair<int,int> x, pair<int,int> y) {return x.second < y.second;});
  }
  {
    int j = 0;
    ll sum = 0;
    for (int i = 0; i < b.size(); i++) {
      while (j < a.size() && a[j].second <= b[i].second) {
	sum += a[j].first;
	j++;
      }
      ans += (ll)j*b[i].first - sum;
    }
  }
  dq(a);
  dq(b);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> p(n);
  for (auto&[x,v] : p) cin >> x;
  for (auto&[x,v] : p) cin >> v;
  dq(p);
  cout << ans << endl;
}