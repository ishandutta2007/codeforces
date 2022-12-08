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
typedef complex<double> cd;
typedef vector<complex<double>> vcd;

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

const int N = 1000;

vector<int> g[N];

// 2 - first bit
// 2 + 30 - last bit

char ans[N][N];

const int L = 30;

void solve() {
	int cur = L + 2;
	g[0].push_back(2);
	for (int i = 2; i < L + 1; i++) { // powers
		g[cur].push_back(i + 1);
		g[i].push_back(cur++);
		g[cur].push_back(i + 1);
		g[i].push_back(cur++);
	}
	int k; cin >> k;
	for (int i = 0; i < L; i++) {
		if ((1 << i) & k) {
			int len = (L - i - 1) * 2 + 1;
			int x = i + 2;
			for (int j = 0; j < len; j++) {
				if (j == len - 1) {
					//cout << j << " " << x << " " << len << endl;
					g[x].push_back(1);
				}
				else {
					g[x].push_back(cur++);
					x = cur - 1;
				}
			}
		}
	}
	cout << cur << endl;
	for (int i = 0; i < cur; i++) {
		for (int j = 0; j < cur; j++)
			ans[i][j] = 'N';
	}
	for (int i = 0; i < cur; i++) {
		for (int j : g[i])
			ans[i][j] = ans[j][i] = 'Y';
	}
	for (int i = 0; i < cur; i++) {
		for (int j = 0; j < cur; j++)
			cout << ans[i][j];
		cout << endl;
	}
	return;
}