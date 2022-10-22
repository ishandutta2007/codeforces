#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  set<pair<int,int>> edge;
  vector<int> p(n);
  for (int&i : p) cin >> i, i--;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    edge.insert({a,b});
  }
  vector<int> remaining;
  remaining.push_back(n-1);
  int ans = 0;
  for (int i = n-2; i >= 0; i--) {
    int ok = 1;
    for (int j : remaining) {
      if (!edge.count({p[i], p[j]})) {
	ok = 0;
	break;
      }
    }
    if (ok) {
      ans++;
    } else {
      remaining.push_back(i);
    }
  }
  cout << ans << endl;
}