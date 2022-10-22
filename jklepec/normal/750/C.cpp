#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
typedef double lf;
typedef long long ll;
typedef pair<int, int> point;

const int mod = 1e9 + 7;
int add(int x, int y) {
	x += y;
	if(x >= mod) return x - mod;
	return x;
}
int sub(int x, int y) {
	x -= y;
	if(x < 0) return x + mod;
	return x;
}
int mul(int x, int y) {
	return (ll) x * y % mod;
}

const int MAXN = 2e5 + 5, inf = 1e9 + 5;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   int mx = -inf, mn = inf, pref = 0;

   int n; cin >> n;
   rep(i, n) {
      int x, d; cin >> x >> d;
      if(d == 1) {
         mn = min(mn, pref);
      }
      else {
         mx = max(mx, pref);
      }
      pref += x;
   }
   if(mx == -inf) {
      cout << "Infinity";
   }
   else if(mn <= mx) {
      cout << "Impossible";
   }
   else
      cout << 1899 - mx + pref;
}