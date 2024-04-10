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

int dp[21][5];

void solve() {
	int t; cin >> t;
	while (t--) {
		ll n; cin >> n;
		for (int i = 0; i < 21; i++)
			for (int j = 0; j < 5; j++)
				dp[i][j] = -1;
		dp[0][0] = 2e9;
		vector<vector<int>> ans(6, vector<int>(19));
		for (int i = 1; i <= 19; i++) {
			for (int j = 0; j < 5; j++) {
				if (dp[i - 1][j] == -1) continue;
				for (int k = 0; k <= 6; k++) {
					for (int h = 0; h <= 6 - k; h++) {
						int t = 6 - k - h;
						int x = 7 * k + 4 * h + j;
						ll c = (n / (ll)pow(10ll, i - 1)) % 10ll;
						if (x % 10 == c)
							dp[i][x / 10] = j;
					}
				}
			}
		}
		if (dp[19][0] == -1) cout << -1 << endl;
		else {
			int x = 0;
			for (int i = 19; i > 0; i--) {;
				int y = dp[i][x];
				bool fl = false;
				for (int k = 0; k <= 6; k++) {
					for (int h = 0; h <= 6 - k; h++) {
						int t = 6 - k - h;
						int mem = 7 * k + 4 * h + y;
						ll c = (n / (ll)pow(10ll, i - 1)) % 10ll;
						if (mem % 10 == c && mem / 10 == x) {
							for (int m = 0; m < k; m++)
								ans[m][i - 1] = 7;
							for (int m = 5; m >= 6 - h; m--)
								ans[m][i - 1] = 4;
							fl = true;
							break;
						}
					}
					if (fl) break;
				}
				x = y;
			}
			for (int i = 0; i < 6; i++) {
				while (!ans[i].empty() && ans[i].back() == 0)
					ans[i].pop_back();
				if (ans[i].empty())
					ans[i].push_back(0);
				reverse(all(ans[i]));
				for (int j : ans[i])
					cout << j;
				cout << " ";
			}
			cout << endl;
		}
	}
	return;
}