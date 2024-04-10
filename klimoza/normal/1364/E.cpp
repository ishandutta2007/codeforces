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
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
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

int n;

const int L = 11;
int id[L];

int ask(int i, int j, int tp = 0) {
	assert(i != j);
	//assert(tp == 1 || (0 <= i && i < n && 0 <= j && j < n));
	cout << "? " << i + 1 << " " << j + 1 << endl;
	int t; cin >> t;
	assert(t != -1);
	return t;
}

int get(int i) {
	int res = 0;
	for (int j = 0; j < L; j++) {
		if (i == id[j]) continue;
		int t = ask(i, id[j], 1);
		if (t & (1 << j))
			res += (1 << j);
	}
	return res;
}

void solve() {
	cin >> n;
	for (int i = 0; i < L; i++) {
		while (true) {
			int a = mrand() % n;
			int b = mrand() % n;
			while (b == a)
				b = mrand() % n;
			int t = ask(a, b, 1);
			if ((t & (1 << i)) == 0) {
				id[i] = a;
				break;
			}
		}
	}
	int	i = 0;
	int val = get(0);
	int ans = 0;
	for (int j = 1; j < n; j++) {
		int t = ask(i, j, 1);
		if ((t & val) == t) {
			i = j;
			val = get(i);
			if (val == 0) {
				ans = i;
				break;
			}
		}
	}
	assert(ans != -1);
	vector<int> a(n);
	for (int j = 0; j < n; j++) {
		if (j == ans)
			a[j] = 0;
		else
			a[j] = ask(j, ans);
	}
	vector<int> b = a;
	sort(all(b));
	vector<int> p;
	for (int i = 0; i < n; i++)
		p.push_back(i);
	assert(b == p);
	cout << "! ";
	for (int j : a)
		cout << j << " ";
	cout << endl;
	return;
}