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

const int MAXN = 1e5 + 5;

int sol = 1e5 + 5;

vector<point> v;
set<int> need;

int a[MAXN];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

   int n, m; cin >> n >> m;

   rep(i, m) {
      int x, y; cin >> x >> y;
      v.emplace_back(x, y);
      sol = min(sol, y - x + 1);
   }

   cout << sol << endl;
   int tmp = 0;
   rep(i, n) {
      cout << tmp % sol << " ";
      tmp ++;
   }
}