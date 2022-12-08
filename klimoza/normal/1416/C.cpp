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

const int N = 3e5 + 7;

const int L = 31;

ll cnt[L][2];

void rec(vector<int> a, int l = L - 1) {
	if (l < 0) return;
	int n = a.size();
	ll s = n * (n - 1) / 2;
	vector<int> zer, one;
	for (int i : a) {
		if (i & (1 << l)) {
			cnt[l][1] += zer.size();
			one.push_back(i);
		}
		else {
			cnt[l][0] += one.size();
			zer.push_back(i);
		}
	}
	if(!zer.empty())
		rec(zer, l - 1);
	if(!one.empty())
		rec(one, l - 1);
}

void solve() {
	for (int i = 0; i < L; i++)
		cnt[i][0] = cnt[i][1] = 0;
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	rec(a);
	ll x = 0;
	ll s = 0;
	for (int i = 0; i < L; i++) {
		if (cnt[i][0] > cnt[i][1]) {
			x += (1ll << i);
			s += cnt[i][1];
		}
		else {
			s += cnt[i][0];
		}
	}
	cout << s << " " << x << endl;
	return;
}