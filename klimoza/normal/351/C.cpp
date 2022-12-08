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

vector<vector<ll>> mul(vector<vector<ll>> a, vector<vector<ll>> b) {
	vector<vector<ll>> res(a.size(), vector<ll>(b[0].size(), inf));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < a[0].size(); k++)
				res[i][j] = min(res[i][j], a[i][k] + b[k][j]);
		}
	}
	return res;
}

vector<vector<ll>> bp(vector<vector<ll>> a, int k) {
	vector<vector<ll>> res(a.size(), vector<ll>(a.size(), inf));
	for (int i = 0; i < a.size(); i++)
		res[i][i] = 0;
	while (k) {
		if (k & 1)
			res = mul(res, a);
		a = mul(a, a);
		k >>= 1;
	}
	return res;
}

const int L = 50;

void solve(){
	int n, m; cin >> n >> m;
	vector<ll> a(n), b(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	vector<vector<ll>> T(L, vector<ll>(L, inf));
	for (int bal = 0; bal < L; bal++) {
		vector<vector<ll>> dp(n + 1, vector<ll>(L, inf));
		dp[0][bal] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < L; j++) {
				//cout << bal << " " << i << " " << j << endl;
				if (j < L - 1) {
					//cout << j << " " << L - 1 << endl;
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j + 1] + b[i]);
				}
				//cout << bal << " " << i << " " << j << endl;
				if(j)
					dp[i + 1][j] = min(dp[i + 1][j], dp[i][j - 1] + a[i]);
			}
		}
		//cout << bal << endl;
		for (int j = 0; j < L; j++)
			T[bal][j] = min(T[bal][j], dp[n][j]);
	}
	vector<vector<ll>> ans = bp(T, m);
	cout << ans[0][0] << endl;
	return;
}