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
 
const int N = 1000 + 10;
const int mod = 1e9 + 7;
 
int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
int n, m, a[N], R[N];
vector<pii> vec;
pii pr[N];
int main() {
	ucin;
	cin >> n;
	rep(i, 1, n) cin >> a[i], pr[i] = pii(a[i], i);
	vector<pii> v;
	rep(i, 1, n) {
		v.clear();
		rep(j, i, n) {
			if(a[j] < a[i]) {
				v.pb(pii(a[j], j));
			}
		}
		sort(v.begin(), v.end(), greater<pii>());
		rep(k, 0, (int) v.size() - 1) {
			vec.pb(mp(i, v[k].sc));
		}
	}
	cout << vec.size() << endl;
	for(auto v : vec) {
		cout << v.fs << ' ' << v.sc << '\n';
	}
	return 0;
}