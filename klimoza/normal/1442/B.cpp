/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
#pragma GCC target("avx2")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
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
#include <stack>
#include <ctime>

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());
//mt19937 mrand(228);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 7;
const ll mod = 998244353;

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

ll mul(ll a, ll b) {
	return a * b % mod;
}

void solve() {
	int t; cin >> t;
	while (t--) {
		int n, k; cin >> n >> k;
		vector<int> a(n), b(k);
		vector<int> l(n), r(n);
		for (int i = 0; i < n; i++) {
			l[i] = i - 1;
			r[i] = i + 1;
		}
		vector<int> id(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			a[i]--;
			id[a[i]] = i;
		}
		vector<int> used(n, -1);
		ll ans = 1;
		for (int i = 0; i < k; i++) {
			cin >> b[i]; b[i]--;
			used[id[b[i]]] = i;
		}
		bool fl = true;
		for (int i = 0; i < k; i++) {
			int j = id[b[i]];
			if (l[j] == -1) {
				if (used[r[j]] > i) {
					fl = false;
					break;
				}
				else {
					r[j] = r[r[j]];
					if(r[j] != n)
						l[r[j]] = j;
				}
			}
			else if (r[j] == n) {
				if (used[l[j]] > i) {
					fl = false;
					break;
				}
				else {
					l[j] = l[l[j]];
					if(l[j] != -1)
						r[l[j]] = j;
				}
			}
			else {
				if (used[l[j]] > i && used[r[j]] > i) {
					fl = false;
					break;
				}
				else if (used[l[j]] > i) {
					r[j] = r[r[j]];
					if(r[j] != n)
						l[r[j]] = j;
				}
				else if (used[r[j]] > i) {
					l[j] = l[l[j]];
					if(l[j] != -1)
						r[l[j]] = j;	
				}
				else {
					ans = mul(ans, 2);
				}
			}
		}
		if (!fl) cout << 0 << endl;
		else cout << ans << endl;
	}
	return;
}