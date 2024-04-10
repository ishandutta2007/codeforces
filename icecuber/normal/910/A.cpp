#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define debug(i) cerr << #i << " = " << i << endl;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, d;
  cin >> n >> d;
  string s;
  cin >> s;
  int p = 0;
  int ans = 0;
  while (p < n-1) {
    ans++;
    int last = p;
    p = min(p+d,n-1);
    while (s[p]=='0') p--;
    if (p == last) {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;
}