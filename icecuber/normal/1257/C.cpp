#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    map<int,int> last;
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (last.count(a)) {
	ans = min(ans, i-last[a]+1);
      }
      last[a] = i;
    }
    cout << (ans == 1e9 ? -1 : ans) << '\n';
  }
}