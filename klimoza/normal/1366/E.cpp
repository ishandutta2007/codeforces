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

mt19937 mrand(43);

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
	map<int, int> mem;
	int n, m; cin >> n >> m;
	vector<int> a(n), b(m);
	int mini = 2e9;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		mini = min(mini, a[i]);
		mem[a[i]] = i;
	}
	for (int i = 0; i < m; i++)
		cin >> b[i];
	if (mini < b[0])
		cout << 0 << endl;
	else {
		ll ans = 1;
		for (int i = 0; i < m; i++) {
			if (mem.find(b[i]) == mem.end()) {
				cout << 0 << endl;
				return;
			}
		}
		vector<pair<int, int>> kek;
		vector<int> prv(n, - 1);
		vector<int> nxt(n, n);
		for (int i = 0; i < n; i++) {
			while (!kek.empty() && kek.back().first >= a[i])
				kek.pop_back();
			if (!kek.empty())
				prv[i] = kek.back().second;
			kek.push_back({ a[i], i });
		}
		kek.clear();
		for (int i = n - 1; i >= 0; i--) {
			while (!kek.empty() && kek.back().first >= a[i])
				kek.pop_back();
			if (!kek.empty())
				nxt[i] = kek.back().second;
			kek.push_back({ a[i], i });
		}
		vector<int> lst(m);
		vector<int> sc(m);
		for (int i = 0; i < m; i++) {
			lst[i] = prv[mem[b[i]]];
			sc[i] = nxt[mem[b[i]]];
			if (sc[i] != n) {
				cout << 0 << endl;
				return;
			}
		}
		for (int i = 1; i < m; i++) {
			//cout << b[i] << " " << mem[b[i]] << endl;
			//cout << b[i + 1] << " " << mem[b[i + 1]] << endl;
			//cout << mem[b[i]] << " " << lst[i] << endl;
			ans = mul(ans, mem[b[i]] - lst[i]);
		}
		cout << ans << endl;
	}
	return;
}