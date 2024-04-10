#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int f(vector<int> a, int d = 29) {
  if (d == -1) return 0;
  if (a.empty()) return 2e9;
  vector<int> l, r;
  for (int v : a) {
    (v>>d&1 ? r : l).push_back(v & ~(1<<d));
  }
  int add = 1<<d;
  if (l.size() % a.size() == 0) add = 0;
  return min(f(l, d-1), f(r, d-1))+add;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int&v : a) cin >> v;
  cout << f(a) << endl;
}