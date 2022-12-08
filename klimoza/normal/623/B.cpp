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
const ld eps = 1e-7;
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

vector<ll> g;

void fac(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			g.push_back(i);
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1)
		g.push_back(n);
}

void solve() {
	int n; cin >> n;
	ll a, b; cin >> a >> b;
	vector<ll> f(n);
	for(int i = 0; i < n; i++)
		cin >> f[i];
	fac(f[0]); fac(f[0] - 1); fac(f[0] + 1);
	fac(f.back()); fac(f.back() - 1); fac(f.back() + 1);
	sort(all(g));
	g.erase(unique(all(g)), g.end());
	ll kek = inf;
	for (int tmp : g) {
		ll ans = 0;
		int l = 0, r = n - 1;
		bool fl = true;
		bool bl = true;
		int cnt = 0;
		for (int i = 0; i < n; i++) {
			if (f[i] % tmp == 0) continue;
			if ((f[i] % tmp != 1) && (f[i] % tmp != (tmp - 1))) fl = false;
			cnt++;
			bl = false;
		}
		if (fl && bl) {
			kek = 0;
			break;
		}
		if (fl) {
			kek = min(kek, cnt * 1LL * b);
			if (b <= a) {
				continue;
			}
			else {
				ll cur = 0;
				ll c = 0;
				for (int i = 0; i < n; i++) {
					if (f[i] % tmp == 0) {
						if (cur < 0) {
							cur = -a;
						} else
							cur -= a;
					}
					else {
						if (cur < 0)
							cur = (b - a);
						else
							cur += (b - a);
					}
					kek = min(kek, cnt * 1LL * b - cur);
				}
			}
			continue;
		}
		cnt = 0;
		for (int i = 0; i < n; i++) {
			if (f[i] % tmp == 0) continue;
			if ((f[i] % tmp == 1) || (f[i] % tmp == (tmp - 1))) cnt++;
			else {
				l = i;
				break;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (f[i] % tmp == 0) continue;
			if ((f[i] % tmp == 1) || (f[i] % tmp == (tmp - 1))) cnt++;
			else {
				r = i;
				break;
			}
		}
		ans = (r - l + 1) * 1LL * a + cnt * 1LL * b;
		ll cur = 0;
		kek = min(kek, ans);
		ll lef = 0;
		for (int i = l - 1; i >= 0; i--) {
			if (f[i] % tmp == 0) cur -= a;
			else cur += (b - a);
			lef = max(lef, cur);
		}
		cur = 0;
		ll rig = 0;
		for (int i = r + 1; i < n; i++) {
			if (f[i] % tmp == 0) cur -= a;
			else cur += (b - a);
			rig = max(rig, cur);
		}
		kek = min(kek, ans - lef - rig);
	}
	cout << kek << endl;
	return;
}