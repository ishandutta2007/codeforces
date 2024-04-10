#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int l, r;
  cin >> l >> r;

  int n = 23;
  cout << "YES" << endl;
  vector<array<int,3>> edge;
  if (l == 1) {
    edge.push_back({0,n-1,1});
    l++;
  }
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n-1; j++) {
      edge.push_back({i,j,1<<max(i-1,0)});
    }
  }
  for (int b = n-2; b >= 0; b--) {
    if (r-l+1 >= 1<<b) {
      edge.push_back({b+1,n-1,l-1});
      l += 1<<b;
    }
  }
  assert(l == r+1);

  cout << n << ' ' << edge.size() << endl;
  for (auto [a,b,c] : edge)
    cout << a+1 << ' ' << b+1 << ' ' << c << endl;
}