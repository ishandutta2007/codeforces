#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <queue>
#include <complex>
 
//#define int long long
 
#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
 
#define endl '\n'
 
using namespace std;
typedef long long ll;
typedef long double ld;
 
mt19937 mrand(random_device{}());
 
double PI = acos((double)-1);
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;
const ll mod2 = mod * mod;
 
void solve();
void scan();
 
signed main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

ll n, k, ln;

const int N = 1e6 + 8;

ll a[N];
pair<ll, int> dp[N];

pair<ll, int> check(ll x) {
	for (int i = 0; i < n; i++) {
		//cout << a[i] + x << endl;
		if (i < (ln - 1)) dp[i] = mp(0, 0);
		else if (i == (ln - 1)) dp[i] = max(mp( 0LL, 0LL ), mp( a[i] + x, 1LL ));
		else dp[i] = max(dp[i - 1], mp( dp[i - ln].first + a[i] + x, dp[i - ln].second + 1 ));
		//if(x == -3)	cout << i << " " << dp[i].first << " " << dp[i].second << endl;	
	}
	return dp[n - 1];
}

void solve() {
	cin >> n >> k >> ln;
	if (k * ln >= n) cout << 0 << endl;
	else {
		string s; cin >> s;
		int cur = 0;
		int cnt1 = 0, cnt2 = 0;
		for (int i = 0; i < n; i++) {
			cur += ('a' <= s[i] && s[i] <= 'z');
			if ('a' <= s[i] && s[i] <= 'z') cnt1++;
			else cnt2++;
			if (i < (ln - 1)) a[i] = 0;
			else if (i == (ln - 1)) a[i] = cur;
			else {
				cur -= ('a' <= s[i - ln] && s[i - ln] <= 'z');
				a[i] = cur;
			}
			//cout << a[i] << " " << i << " " << cur << endl;
		}
		ll l = -1e10, r = 1;
		pair<ll, int> x;
		//x = check();
		//return;
		int cnt = 0;
		while (r - l > 1) {
			//cnt++;
			ll m = (l + r) / 2;
			//cout << m << endl;
			x = check(m);
			//if (cnt == 2) return;
			if (x.second >= k)	r = m;
			else l = m;
		}
		x = check(r);
		ll ans = cnt2 + x.first - r * k;
		//cout << x.first << " " << x.second << " " << r << endl;
		//cout << ans << endl;
		for (int i = (ln - 1); i < n; i++) {
			a[i] = ln - a[i];
		}
		l = -1e10, r = 1;
		while (r - l > 1) {
			ll m = (l + r) / 2;
			x = check(m);
			if (x.second >= k) r = m;
			else l = m;
		}
		x = check(r);
		ans = max(ans, cnt1 + (ll)(x.first - r * k));
		//cout << x.first << " " << x.second << " " << r << endl;
		cout << n - ans << endl;
	}
	return;
}