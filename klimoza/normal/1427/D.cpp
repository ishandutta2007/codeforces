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

struct Item {
	int l, r;
	Item() {}
	Item(int l, int r) :l(l), r(r) {}
};

vector<Item> check(vector<Item> a) {
	vector<Item> c = { a[0] };
	for (int i = 1; i < a.size(); i++) {
		if (c.back().r + 1 == a[i].l)
			c.back().r = a[i].r;
		else
			c.push_back(a[i]);
	}
	return c;
}

void solve() {
	int n; cin >> n;
	vector<Item> a(n);
	for (int i = 0; i < n; i++) {
		int c; cin >> c;
		a[i] = Item(c, c);
	}
	vector<vector<int>> ans;
	a = check(a);
	while (true) {
		int t1 = -1, t2 = -1;
		vector<Item> b;
		n = a.size();
		if (n == 1)
			break;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (a[i].l== a[j].r + 1) {
					t1 = i;
					t2 = j;
				}
			}
		}
		if (t1 == -1) {
			ans.push_back(vector<int>());
			for (auto u : a)
				ans.back().push_back(u.r - u.l + 1);
			break;
		}
		else {
			/*for (auto u : a)
				cout << u.l << " " << u.r << endl;
			cout << "lol\n";*/
			int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
			for (int i = 0; i < t1; i++)
				s1 += a[i].r - a[i].l + 1;
			s2 = a[t1].r - a[t1].l + 1;
			for (int i = t1 + 1; i <= t2; i++)
				s3 += a[i].r - a[i].l + 1;
			for (int i = t2 + 1; i < n; i++)
				s4 += a[i].r - a[i].l + 1;
			ans.push_back(vector<int>());
			if (s1)
				ans.back().push_back(s1);
			if(s2)
				ans.back().push_back(s2);
			if(s3)
				ans.back().push_back(s3);
			if(s4)
				ans.back().push_back(s4);
			for (int i = t2 + 1; i < n; i++)
				b.push_back(a[i]);
			for (int i = t1 + 1; i < t2; i++)
				b.push_back(a[i]);
			a[t2].r = a[t1].r;
			b.push_back(a[t2]);
			for (int i = 0; i < t1; i++)
				b.push_back(a[i]);
			a = check(b);
		}
	}
	cout << ans.size() << endl;
	for (auto u : ans) {
		cout << u.size() << " ";
		for (int i : u)
			cout << i << " ";
		cout << endl;
	}
	return;
}