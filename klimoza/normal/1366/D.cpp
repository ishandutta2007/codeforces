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

int gcd(int a, int b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}

const int N = 1e7 + 1;

int lp[N];

void solve() {
	vector<int> pr;
	fill(lp, lp + N, -1);
	for (int i = 2; i < N; i++) {
		if (lp[i] == -1) {
			lp[i] = i;
			pr.push_back(i);
		}
		for (int j = 0; j < pr.size() && pr[j] <= lp[i] && pr[j] * 1ll * i < N; j++) {
			lp[pr[j] * i] = pr[j];
		}
	}
	int n; cin >> n;
	vector<int> d1(n, -1), d2(n, -1);
	for (int i = 0; i < n; i++) {
		int y; cin >> y;
		int a = lp[y];
		while (y % (a * 1ll * lp[y]) == 0)
			a *= lp[y];
		if (a != y && gcd(a + y / a, y) == 1) {
			d1[i] = a;
			d2[i] = y / a;
		} 
	}
	for (int i = 0; i < n; i++)
		cout << d1[i] << " ";
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << d2[i] << " ";
	return;
}