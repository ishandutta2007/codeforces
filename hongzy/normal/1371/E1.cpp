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
typedef unsigned long long ull;

const int N = 2000 + 10;
const int mod = 1e9 + 7;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int p, n, a[N];
vector<int> ans; 
int main() {
	scanf("%d%d", &n, &p);
	rep(i, 1, n) scanf("%d", a + i);
	sort(a + 1, a + n + 1);
	rep(x, max(a[n] - n + 1, a[1]), a[n]) {
		ll r = 1;
		int j = 0;
		rep(i, 1, n) {
			while(j < n && a[j + 1] <= x + i - 1) j ++;
			r = r * (j - i + 1ll) % p;
		}
		if(r) ans.pb(x);
	}
	cout << ans.size() << endl;
	for(int v :ans) printf("%d ", v);
	return 0;
}