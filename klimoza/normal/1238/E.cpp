#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <random>
#include <deque>
#include <bitset>
#include <string>
#include <complex>

//#define int long long

#define endl '\n'
#define all(v) (v).begin(), (v).end()

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const double eps = 1e-6;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
const ll mod = 1e9 + 7;

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

const int a = 'z' + 1;
const int M = 21;
const int N = (1 << 21);

int cnt[a][a];
ll dp[N];

void solve() {
	int n, m;
	cin >> n >> m;
	string st;
	cin >> st;
	for (int i = 0; i <= 'z'; i++) {
		fill(cnt[i], cnt[i] + 'z' + 1, 0);
	}
	for (int i = 0; i < n - 1; i++) {
		cnt[st[i]][st[i + 1]]++;
		cnt[st[i + 1]][st[i]]++;
	}
	fill(dp, dp + N, inf);
	dp[0] = 0;
	for (int i = 0; i < (1 << m); i++) {
		ll pos = 0;
		for (int j = 0; j < m; j++) {
			if (i & (1 << j)) pos++;
		}
		//cout << pos << endl;
		for (int j = 0; j < m; j++) {
			ll cur = 0;
			if (i & (1 << j)) continue;
			for (int k = 0; k < m; k++) {
				if (k == j) continue;
				if (i & (1 << k))
					cur += cnt[j + 'a'][k + 'a'] * pos;
				else
					cur -= cnt[j + 'a'][k + 'a'] * pos;
				//cout << (char)(k + 'a') << " " << (char)(j + 'a') << endl;
			}
			//cout << i << " " << j << " " << cur << " " << dp[i] << endl;
			dp[i | (1 << j)] = min(dp[i | (1 << j)], dp[i] + cur);
		}
	}
	cout << dp[(1 << m) - 1] << endl;
}