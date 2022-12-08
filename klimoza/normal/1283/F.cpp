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

const int N = 2e5 + 7;

vector<int> g[N];
int t[N];

void solve() {
	fill(t, t + N, -1);
	int n; cin >> n;
	vector<int> a(n - 1);
	for (int i = 0; i < n - 1; i++) {
		cin >> a[i];
		if (t[a[i]] == -1) t[a[i]] = i;
	}
	set<int> f;
	for (int i = 1; i <= n; i++) f.insert(i);
	set<int> used;
	vector<pair<int, int>> ed;
	for (int i = 0; i < (n - 1); i++) {
		f.erase(a[i]);
		used.insert(a[i]);
		if (f.empty()) {
			cout << -1 << endl;
			return;
		}
		if (i == (n - 2) || used.find(a[i + 1]) != used.end()) {
			int h = *f.rbegin();
			//cout << a[i] << " " << h << " lol\n";
			ed.push_back(mp(a[i], h));
			f.erase(h);
			used.insert(h);
		}
		else {
			ed.push_back(mp(a[i], a[i + 1]));
		}
	}
	if (!f.empty()) cout << -1 << endl;
	else {
		cout << a[0] << endl;
		for (auto u : ed) cout << u.first << " " << u.second << endl;
	}
	return;
}