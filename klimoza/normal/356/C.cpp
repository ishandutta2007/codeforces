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

mt19937 mrand(239);

const double PI = acos((double)-1);
const double eps = 1e-5;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1009;
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

const int N = 4e6;

int pref[N], lol[N];

void solve(){
	fill(pref, pref + N, 0);
	fill(lol, lol + N, 0);
	int n; cin >> n;
	vector<int> a(n);
	int s = 0;
	int c = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 4) c++;
		s += a[i];
	}
	sort(rall(a));
	pref[0] = a[0];
	for (int i = 1; i < N; i++) {
		if (i >= n) pref[i] = pref[i - 1];
		else pref[i] = pref[i - 1] + a[i];
	}
	lol[0] = abs(3 - a[0]);
	for (int i = 1; i < N; i++) {
		if (i >= n) lol[i] = lol[i - 1];
		else lol[i] = lol[i - 1] + abs(3 - a[i]);
	}
	int ans = 2e9;
	for (int i = 0; i <= n; i++) {
		if (s < i * 4) break;
		if ((s - i * 4) % 3) continue;
		int l = (s - i * 4) / 3;
		int x = s - pref[i + l - 1];
		//cout << x << endl;
		if (!i) x += 4 * i;
		else x += 4 * i - pref[i - 1];
		//cout << x << endl;
		if (!i) x += lol[i + l - 1];
		else x += (lol[i + l - 1] - lol[i - 1]);
		//cout << i << "  " << x << " " << l << endl;
		ans = min(ans, x);
	}
	if (ans == 2e9) cout << -1 << endl;
	else cout << ans / 2<< endl;
	return;
}