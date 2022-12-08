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

const int N = 2e5 + 7;

int tmp[N];

void solve() {
	int n, k; cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int r = 1e9;
	int l = 0;
	while (r - l > 1) {
		int m = l + r >> 1;
		bool fl = false;
		fill(tmp, tmp + n, 0);
		for (int i = 0; i < n; i++) {
			if(i)
				tmp[i] = tmp[i - 1];
			if (a[i] <= m) {
				if (i == 0)
					tmp[i] = max(tmp[i], 1);
				else if (i == 1)
					tmp[i] = max(tmp[i], 2);
				else
					tmp[i] = max(tmp[i], tmp[i - 2] + 2);
			}
			if (tmp[i] == k || (i < (n - 1) && tmp[i] == k - 1))
				fl = true;
		}
		if (fl)
			r = m;
		else
			l = m;
	}
	cout << r << endl;
	return;
}