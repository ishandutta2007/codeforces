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
 
const int N = 3e5 + 10;
const int mod = 1e9 + 7;
 
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int n, m, a[N], l[N], r[N], Pla[N], Sla[N];
bool pre[N], suf[N];
int main() {
	ucin;
	int t; cin >> t;
	while(t --) {
		cin >> n;
		rep(i, 1, n) cin >> a[i];
		bool tag = a[1] < a[n];
		cout << (tag ? "YES" : "NO") << endl;
	}
	return 0;
}