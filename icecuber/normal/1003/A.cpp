#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  map<int,int> m;
  int n;
  cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    ans = max(ans, ++m[v]);
  }
  cout << ans << endl;
}