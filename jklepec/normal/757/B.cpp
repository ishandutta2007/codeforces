#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for(int i = a; i < b; ++i)
#define REP(i, n) for(int i = 0; i < n; ++i)
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

const int MAXN = 2e5 + 5;

int a[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   int n; cin >> n;
   REP(i, n) {
      int x; cin >> x;
      a[x] ++;
   }

   int sol = 1;
   FOR(i, 2, MAXN) {
      int tmp = 0;
      for(int j = i; j < MAXN; j += i) tmp += a[j];
      sol = max(tmp, sol);
   }

   cout << sol;
}