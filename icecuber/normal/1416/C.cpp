#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

pair<ll,int> dq(const vector<vector<int>>&a, int bit) {
  if (bit < 0) return {0,0};
  vector<vector<int>> R;
  ll b0 = 0, b1 = 0;
  for (auto&v : a) {
    vector<int> l, r;
    int ones = 0, zeros = 0;
    for (int i : v) {
      if (i>>bit&1) {
	ones++;
	b1 += zeros;
	r.push_back(i);
      } else {
	zeros++;
	b0 += ones;
	l.push_back(i);
      }
    }
    if (l.size())
      R.push_back(l);
    if (r.size())
      R.push_back(r);
  }
  auto [b_,x_] = dq(R, bit-1);
  int x = (b1 < b0);
  ll b = min(b0, b1);
  return {b+b_, x<<bit | x_};
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  auto [b,x] = dq({a}, 30);
  cout << b << ' ' << x << endl;
}