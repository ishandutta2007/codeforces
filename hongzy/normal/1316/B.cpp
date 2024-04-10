#include <bits/stdc++.h>
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
typedef unsigned long long ull;

const int N = 4e5 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}

int main() {
	ucin; int t; cin >> t;
	while(t --){
		string s, cur;
		int n; cin >> n >> s;
		string ans = s; int res = 1;
		for(int k = 2; k <= n; k ++) {
			cur.clear();
			for(int i = k; i <= n; i ++) cur.pb(s[i - 1]);
			if((n - k + 1) % 2 == 0) {
				for(int i = 1; i < k; i ++) cur.pb(s[i - 1]);
			} else {
				for(int i = k - 1; i >= 1; i --) cur.pb(s[i - 1]);
			}
			if(cur < ans) {
				ans = cur; res = k;
			}
		}
		cout << ans << '\n' << res << '\n';
	}
	return 0;
}