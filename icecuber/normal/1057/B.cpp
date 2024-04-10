#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> acc(n+1,0);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    acc[i+1] = acc[i]+x;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      if (acc[j]-acc[i] > 100*(j-i))
	ans = max(ans, j-i);
    }
  }
  cout << ans << endl;
}