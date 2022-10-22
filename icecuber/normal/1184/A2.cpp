#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  string s;
  cin >> n >> s;
  map<int,int> mem;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int g = __gcd(i,n);
    if (!mem.count(g)) {
      int ok = 1;
      for (int j = 0; j < g; j++) {
	int f = 0;
	for (int k = j; k < n; k += g)
	  f ^= s[k] == '1';
	ok &= f==0;
      }
      mem[g] = ok;
    }
    ans += mem[g];
  }
  cout << ans << endl;
}