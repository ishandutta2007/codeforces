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
 
const int N = 4e5 + 10;
const int mod = 1e9 + 7;
 
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int n, a[N];
int main() {
	int t; cin >> t;
	while(t --) {
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		int f = 1;
		rep(i, 1, n) {
			a[i] = abs(a[i]);
			if(f == -1) a[i] = -a[i];
			f = -f;
		}
		rep(i, 1, n) cout << a[i] << ' ';
		cout << endl;
	}
	return 0;
}