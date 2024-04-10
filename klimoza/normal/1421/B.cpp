
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

const int N = 201;
char f[N][N];

void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				cin >> f[i][j];
		}
		vector<pair<int, int>> ans;
		if (f[0][1] == f[1][0]) {
			if (f[n - 1][n - 2] == f[0][1])
				ans.push_back({ n - 1, n - 2 });
			if (f[n - 2][n - 1] == f[0][1])
				ans.push_back({ n - 2, n - 1 });
		}
		else if(f[n - 1][n - 2] == f[n - 2][n - 1]){
			if (f[n - 1][n - 2] == f[0][1])
				ans.push_back({ 0, 1 });
			if (f[n - 1][n - 2] == f[1][0])
				ans.push_back({ 1, 0 });
		}
		else if (f[n - 1][n - 2] == f[0][1]) {
			ans.push_back({ n - 1,n - 2 });
			ans.push_back({ 1, 0 });
		}
		else {
			ans.push_back({ n - 1, n - 2 });
			ans.push_back({ 0, 1 });
		}
		cout << ans.size() << endl;
		for (auto u : ans)
			cout << u.first + 1 << " " << u.second + 1 << endl;
	}
	return;
}