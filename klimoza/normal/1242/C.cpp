#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <map>
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

#define int long long

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

map<ll, ll> f;

const int K = 1 << 15;

bool p[K];
vector<pair<int, int>> res[K];
pair<int, int> lol[K];
pair<int, int> ans[K];

void getans(int mask) {
	if (!mask) return;
	//cout << mask << endl;
	if (lol[mask] != mp(-1ll, -1ll)) {
		getans( lol[mask].first);
		getans(lol[mask].second);
	}
	else {
		for (int i = 1; i < res[mask].size(); i++) {
			ans[res[mask][i].first] = { res[mask][i - 1].first, res[mask][i].second };
		}
		ans[res[mask][0].first] = { res[mask].back().first, res[mask][0].second };
	}
}

void solve() {
	for (int i = 0; i < K; i++) {
		p[i] = false;
		lol[i] = { -1, -1 };
	}
	int k; cin >> k;
	vector<vector<int>> a(k);
	for (int i = 0; i < k; i++) {
		int n; cin >> n;
		a[i].resize(n);
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			f[a[i][j]] = i;
		}
	}
	ll s = 0;
	vector<ll> su(k);
	for (int i = 0; i < k; i++) {
		for (ll j : a[i])
			su[i] += j;
		s += su[i];
	}
	if (s % k) {
		cout << "No\n";
		return;
	}
	s /= k;
	for (int i = 0; i < k; i++) {
		for (int j : a[i]) {
			int mask = 0;
			vector<bool> used(k);
			vector<pair<int, int>> cur;
			int kek = j;
			int id = i;
			while (!used[id]) {
				mask |= 1 << id;
				used[id] = true;
				cur.push_back({ id, kek });
				kek = s - su[id] + kek;
				if (f.find(kek) == f.end()) {
					id = -1;
					break;
				}
				id = f[kek];
			}
			if (id == -1) continue;
			if (!p[mask] && kek == j) {
				p[mask] = true;
				res[mask] = cur;
			}
		}
	}
	p[0] = true;
	for (int mask = 0; mask < (1 << k); mask++) {
		if (p[mask]) {
			continue;
		}
		for (int j = mask; j > 0; j = (j - 1) & mask) {
			if (p[j] && p[mask ^ j]) {
				p[mask] = true;
				lol[mask] = mp( j, (mask ^ j) );
				break;
			}
		}
	}
	if (!p[(1 << k) - 1]) cout << "No\n";
	else {
		cout << "Yes\n";
		getans((1 << k) - 1);
		for (int i = 0; i < k; i++)
			cout << ans[i].second << " " << ans[i].first + 1 << endl;
	}
	return;
}