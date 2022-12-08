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

mt19937 mrand(43);

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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	cout << fixed; cout.precision(15);
	solve();
	return 0;
}

int askAND(int i, int j) {
	cout << "AND " << i + 1 << " " << j + 1 << endl;
	int t; cin >> t;
	return t;
}

int askXOR(int i, int j) {
	cout << "XOR " << i + 1 << " " << j + 1 << endl;
	int t; cin >> t;
	return t;
}

vector<int> pref;

int get(int i, int j) {
	if (i > j) swap(i, j);
	return pref[j] ^ pref[i];
}

void solve() {
	int n; cin >> n;
	pref.resize(n);
	pref[0] = 0;
	map<int, int> kek;
	kek[0] = 0;
	vector<int> a(n);
	int j = -1;
	for (int i = 0; i < n - 1; i++) {
		int t = askXOR(i, i + 1);
		pref[i + 1] = pref[i] ^ t;
		if (j == -1 && kek.find(pref[i + 1]) != kek.end()) {
			int t = askAND(kek[pref[i + 1]], i + 1);
			j = i + 1;
			a[j] = t;
		}
		kek[pref[i + 1]] = i + 1;
	}
	if (j == -1) {
		int t1 = 0;
		int t2 = -1;
		int t3 = -1;
		for (int i = 1; i < n; i++) {
			if (get(t1, i) == 1) t2 = i;
			if (get(t1, i) % 2 == 0) t3 = i;
		}
		a[0] = askAND(t1, t2) ^ (askAND(t1, t3) & 1);
		j = 0;
	}
	for (int i = 0; i < n; i++) {
		a[i] = a[j] ^ get(i, j);
	}
	cout << "! ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	return;
}