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

const int S = 5e5 + 1;
const int N = 51;

bool dp[N][S];

bool mem[S];

void solve(){
	int n, d; cin >> n >> d;
	dp[0][0] = true;
	mem[0] = true;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		for (int j = 0; j < S; j++) {
			dp[i + 1][j] = dp[i][j];
			if (j >= x)
				dp[i + 1][j] = dp[i + 1][j] || dp[i][j - x];
			if (dp[i + 1][j])
				mem[j] = true;
		}
	}
	int c = 0;
	int ans = 0;
	while(true){
		int kek = c;
		for (int i = c; i <= min(S - 1,c + d); i++) {
			if (mem[i])
				kek = i;
		}
		if (kek != c) {
			c = kek;
			ans++;
		}
		else {
			break;
		}
	}
	cout << c << " " << ans << endl;
	return;
}