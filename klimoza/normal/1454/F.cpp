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

//#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

const double PI = acos((double)-1);
const double eps = 1e-5;
const int inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * 1ll * inf0;
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

const int N = 2e5 + 2;

int bigleft[N], smallleft[N], bigright[N], smallright[N];

pair<int, int> intersect(int l1, int r1, int l2, int r2) {
	return mp(max(l1, l2), min(r1, r2));
}

void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			bigleft[i] = smallleft[i] = -1;
			bigright[i] = smallright[i] = n;
		}
		vector<int> a(n);
		vector<pair<int, int>> b(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = { a[i], i };
		}
		sort(all(b));
		a[b[0].second] = 0;
		for (int i = 1; i < n; i++) {
			if (b[i].first == b[i - 1].first)
				a[b[i].second] = a[b[i - 1].second];
			else
				a[b[i].second] = a[b[i - 1].second] + 1;
		}
		{
			vector<pair<int, int>> kek;
			for (int i = 0; i < n; i++) {
				while (!kek.empty() && kek.back().first <= a[i])
					kek.pop_back();
				if (!kek.empty())
					bigleft[i] = kek.back().second;
				kek.push_back(mp(a[i], i));
			}
			kek.clear();
			for (int i = 0; i < n; i++) {
				while (!kek.empty() && kek.back().first >= a[i])
					kek.pop_back();
				if (!kek.empty())
					smallleft[i] = kek.back().second;
				kek.push_back(mp(a[i], i));
			}
			kek.clear();
			for (int i = n - 1; i >= 0; i--) {
				while (!kek.empty() && kek.back().first <= a[i])
					kek.pop_back();
				if (!kek.empty())
					bigright[i] = kek.back().second;
				kek.push_back(mp(a[i], i));
			}
			kek.clear();
			for (int i = n - 1; i >= 0; i--) {
				while (!kek.empty() && kek.back().first >= a[i])
					kek.pop_back();
				if (!kek.empty())
					smallright[i] = kek.back().second;
				kek.push_back(mp(a[i], i));
			}
			kek.clear();
		}
		int x = -1, y = -1, z = -1;
		int cur = 0;
		vector<vector<int>> id(n);
		for (int i = 0; i < n; i++)
			id[a[i]].push_back(i);
		for (int i = 0; i < n; i++) {
			cur = max(cur, a[i]);
			int f1 = upper_bound(all(id[cur]), i) - id[cur].begin();
			if (id[cur].size() == f1) continue;
			f1 = id[cur][f1];//f1 -   
			if (smallleft[f1] > i) continue;
			int f2 = smallright[f1]; //f2 -     (f1, f2]
			int h2 = id[cur].back(); //h2 -   
			if (bigright[h2] != n) continue;
			int h1 = bigleft[h2]; //h1 -    (h1, h2]
			pair<int, int> kek = intersect(f1 + 1, f2, h1 + 1, h2);
			if (kek.first > kek.second) continue;
			x = i + 1;
			y = kek.first;
		}
		if (x == -1) cout << "NO\n";
		else {
			y = y - x;
			z = (n - x - y);
			cout << "YES\n";
			cout << x << " " << y << " " << z << endl;
		}
	}
	return;
}