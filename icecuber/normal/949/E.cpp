#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> bad(20);
vector<int> f(vector<int> a, int d = 0) {
  if (d == 20) return bad;
  a.resize(unique(a.begin(),a.end())-a.begin());
  if (a.size() == 1 && a[0] == 0) {
    return {};
  }
  int odd = 0;
  for (int v : a) odd |= v%2;
  if (odd) {
    vector<int> x,y;
    for (int v : a) {
      if (v%2) {
	x.push_back((v+1)/2);
	y.push_back((v-1)/2);
      } else {
	x.push_back(v/2);
	y.push_back(v/2);
      }
    }
    auto a = f(x,d+1);
    auto b = f(y,d+1);
    a.push_back(-1<<d);
    b.push_back(1<<d);
    return a.size() < b.size() ? a : b;
  } else {
    for (int&v : a) v /= 2;
    return f(a, d+1);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  sort(a.begin(), a.end());
  auto ans = f(a);
  cout << ans.size() << endl;
  for (int v : ans)
    cout << v << ' ';
  cout << endl;
}