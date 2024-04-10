//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,popcnt,abm,mmx,tune=native")
//#pragma GCC target("avx2")
//#pragma GCC optimize("no-stack-protector")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("fast-math")
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

const double PI = acos((double)-1);
const double eps = 1e-5;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
const ll mod = 1e9 + 7;
//const ll mod = 998244353;

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

void solve() {
	int t; cin >> t;
	while (t--) {
		int n;  cin >> n;
		vector<int> a(n);
		vector<pair<int, int>> foo(n + 1, mp(-1, -1));
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			foo[a[i]].second = i;
			if (foo[a[i]].first == -1)
				foo[a[i]].first = i;
		}
		vector<int> prv(n, -1);
		vector<int> nxt(n, n);

		vector<pair<int, int>> kek;
		for (int i = 0; i < n; i++) {
			while (!kek.empty() && kek.back().first >= a[i])
				kek.pop_back();
			if (!kek.empty())
				prv[i] = kek.back().second;
			kek.push_back(mp(a[i], i));
		}
		kek.clear();
		for (int i = n - 1; i >= 0; i--) {
			while (!kek.empty() && kek.back().first >= a[i])
				kek.pop_back();
			if (!kek.empty())
				nxt[i] = kek.back().second;
			kek.push_back(mp(a[i], i));
		}
		//vector<int> b = a;
		set<int> p;
		for (int i = 0; i < n; i++)
			p.insert(a[i]);
		//sort(all(b));
		vector<int> ans(n, 1);
		//if (p != b) ans[0] = 0;
		int lol = 0;
		for (int i = 1; i <= n; i++) {
			if (p.find(i) == p.end()) {
				lol = n - i + 1;
				break;
			}
		}
		int m = 1;
		for (int i = 1; i <= n; i++)
			m = max(m, foo[i].second - foo[i].first + 1);
		for (int i = 0; i < n; i++) {
			if ((prv[i] == i - 1) || (nxt[i] == i + 1)) continue;
			int len = nxt[i] - prv[i] - 1;
			m = max(m, len);
		}
		for (int i = 0; i < n; i++) {
			if ((i + 1) <= lol) cout << 0;
			else if (i && (i + 1) < m) cout << 0;
			else cout << 1;
		}
		cout << endl;
	}
	return;
}