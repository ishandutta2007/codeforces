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

//#define int long long

#define mp(a, b) make_pair(a, b)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()

#define endl '\n'


using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-7;
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

string kek[10] = { "1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011" };
int nm[10];

const int N = 2e3 + 7;
const int K = (1 << 10);
int cnt[K];

void build() {
	for (int i = 0; i < 10; i++) {
		nm[i] = 0;
		for (int j = 0; j < 7; j++) {
			if (kek[i][j] == '1')
				nm[i] += (1 << j);
		}
	}
	for (int i = 0; i < K; i++) {
		cnt[i] = 0;
		for (int j = 0; j < 10; j++) {
			if ((1 << j) & i)
				cnt[i]++;
		}
	}
}


bool dp[N][N];

int get(string& s) {
	int a = 0;
	for (int j = 0; j < 7; j++) {
		if (s[j] == '1')
			a += (1 << j);
	}
	return a;
}

void solve() {
	build();
	int n, k; cin >> n >> k;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = false;
		}
	}
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		a[i] = get(s);
	}
	dp[n][0] = true;
	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j <= k; j++) {
			for (int t = 0; t <= 9; t++) {
				if ((nm[t] & a[i]) != a[i]) continue;
				int msk = nm[t] ^ a[i];
				if (cnt[msk] > j) continue;
				dp[i][j] |= dp[i + 1][j - cnt[msk]];
			}
			//cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	if (!dp[0][k]) cout << -1 << endl;
	else {
		string ans = "";
		for (int i = 0; i < n; i++) {
			for (int t = 9; t >= 0; t--) {
				if ((nm[t] & a[i]) != a[i]) continue;
				int msk = nm[t] ^ a[i];
				if (cnt[msk] > k || !dp[i + 1][k - cnt[msk]]) continue;
				ans += (t + '0');
				k -= cnt[msk];
				break;
			}
		}
		cout << ans << endl;
	}
	return;
}