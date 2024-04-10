#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
 
#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
 
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned uint;
typedef unsigned long long ull;
 
const int N = 500 + 10;
const int mod = 1e9 + 7;
 
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int n, m, a[N][N], b[N][N];
int main() {
	ucin;
	int t; cin >> t;
	while(t --) {
		cin >> n >> m; bool tag = 0;
		rep(i, 1, n) rep(j, 1, m) {
			cin >> a[i][j];
			b[i][j] = 4 - (i == 1) - (j == 1) - (i == n) - (j == m);
			if(a[i][j] > b[i][j]) tag = 1;
		}
		if(tag) cout << "NO\n";
		else {
			cout << "YES\n";
			rep(i, 1, n) {
				rep(j, 1, m) cout << b[i][j] << ' ';
				cout << endl;
			}
		}
	}
	return 0;
}