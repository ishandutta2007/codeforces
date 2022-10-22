#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int query(int x, int y) {
  assert(x != y);
  cout << "? " << x+1 << ' ' << y+1 << endl;
  int ans;
  cin >> ans;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> ans(n);
  int cur = 0;
  for (int i = 1; i < n; i++) {
    int a = query(cur,i);
    int b = query(i,cur);
    assert(a != b);
    if (a > b) ans[cur] = a, cur = i;
    else ans[i] = b;
  }
  ans[cur] = n;
  cout << "!";
  for (int v : ans) cout << ' ' << v;
  cout << endl;
}