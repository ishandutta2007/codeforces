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

#define int long long

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

const int N = 1e7 + 2;

int p[N];

int cnt_num[N], cnt_p[N];

void build_sieve() {
	fill(p, p + N, -1);
	fill(cnt_num, cnt_num + N, 0);
	fill(cnt_p, cnt_p + N, 0);
	for (int i = 2; i < N; i++) {
		if (p[i] == -1) {
			p[i] = i;
			for (ll j = i * 1ll * i; j < N; j += i)
				if(p[j] == -1)
					p[j] = i;
		}
	}
}


void solve() {
	build_sieve();
	int k; cin >> k;
	vector<int> a(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
		cnt_num[a[i]]++;
	}
	for (int i = N - 2; i >= 0; i--) {
		cnt_num[i] += cnt_num[i + 1];
	}
	for (int i = N - 1; i > 1; i--) {
		if (p[i] != i) {
			cnt_num[i / p[i]] += cnt_num[i];
			cnt_num[p[i]] += cnt_num[i];
		}
		else {
			cnt_p[i] = cnt_num[i];
		}
	}
	int l = 0, r = 1e18;
	vector<int> pp;
	for (int i = 2; i < N; i++)
		if (p[i] == i)
			pp.push_back(i);
	while (r - l > 1) {
		int m = l + r >> 1;
		bool fl = true;
		for (int i : pp) {
			int c = 0;
			for (int j = i; j <= m; j *= i)
				c += m / j;
			if (c < cnt_p[i]) {
				fl = false;
				break;
			}
		}
		if (fl) r = m;
		else l = m;
	}
	cout << r << endl;
	return;
}