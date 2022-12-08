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

const int N = 3e5 + 7;

int n;

ll a[N];

ll s = 0;

void add(int i) {
	if (i < 0 || i >= n) return;
	if(i > 0 && i < (n - 1)){
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
			s += a[i];
		if (a[i] < a[i - 1] && a[i] < a[i + 1])
			s -= a[i];
	}
	else if (i == 0 && (n == 1 || a[0] > a[1]))
		s += a[0];
	else if (i == (n -  1) && (n == 1 || a[n - 1] > a[n - 2]))
		s += a[n - 1];
}

void sub(int i) {
	if (i < 0 || i >= n) return;
	if (i > 0 && i < (n - 1)) {
		if (a[i] > a[i - 1] && a[i] > a[i + 1])
			s -= a[i];
		if (a[i] < a[i - 1] && a[i] < a[i + 1])
			s += a[i];
	}
	else if (i == 0 && (n == 1 || a[0] > a[1]))
		s -= a[0];
	else if (i == (n - 1) && (n == 1 || a[n - 1] > a[n - 2]))
		s -= a[n - 1];
}

void solve() {
	fill(a, a + N, 0);
	int t; cin >> t;
	while (t--) {
		int q; cin >> n >> q;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		s = 0;
		for (int i = 0; i < n; i++) {
			add(i);
		}
		cout << s << endl;
		for (int i = 0; i < q; i++) {
			int l, r; cin >> l >> r; l--; r--;
			sub(l - 1);
			sub(l);
			sub(l + 1);
			if ((r - 1) != (l - 1) && (r - 1) != l && (r - 1) != (l + 1))
				sub(r - 1);
			if ((r) != (l - 1) && (r) != l && (r) != (l + 1))
				sub(r);
			if ((r + 1) != (l - 1) && (r + 1) != l && (r + 1) != (l + 1))
				sub(r + 1);
			swap(a[l], a[r]);
			add(l - 1);
			add(l);
			add(l + 1);
			//cout << a[l] << " " << a[l + 1] << endl;
			//cout << s << endl;
			if ((r - 1) != (l - 1) && (r - 1) != l && (r - 1) != (l + 1))
				add(r - 1);
			if ((r) != (l - 1) && (r) != l && (r) != (l + 1))
				add(r);
			if ((r + 1) != (l - 1) && (r + 1) != l && (r + 1) != (l + 1))
				add(r + 1);
			cout << s << endl;
		}
	}
	return;
}