#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    cout << 1 << ' ' << 1 << endl;
    return 0;
  }
  vector<array<int,2>> ans;
  while (n%3 != 2) {
    ans.push_back({n-1,n-1});
    n--;
  }
  int k = (n+1)/3;
  for (int i = 0; i < k; i++) {
    ans.push_back({i*2,i});
  }
  for (int i = 0; i < k-1; i++) {
    ans.push_back({i*2+1,k+i});
  }

  cout << ans.size() << endl;
  for (auto [x,y] : ans) cout << x+1 << ' ' << y+1 << endl;
}