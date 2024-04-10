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

const int N = 24;
const int K = 1 << N;

int cnt[K], lol[K];

void solve() {
	fill(cnt, cnt + K, 0);
	fill(lol, lol + K, 0);
	int n; cin >> n;
	int all = K - 1;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int x = (1 << (s[0] - 'a'));
		if (s[1] != s[0]) x += (1 << (s[1] - 'a'));
		if (s[2] != s[0] && s[2] != s[1]) x += (1 << (s[2] - 'a'));
		cnt[x]++;
		lol[x]++;
		//cout << x << endl;
	}
	for (int mask = 1; mask < K; mask++) {
		if ((mask & (mask - 1)) == 0) continue;
		int tmp = mask & (mask - 1);
		int x = mask - (mask & (mask - 1));
		int y = tmp - (tmp & (tmp - 1));
		if ((mask ^ x ^ y) == 0) {
			cnt[mask] = cnt[mask ^ x] + cnt[mask ^ y] - cnt[mask ^ x ^ y] + lol[x ^ y];
			//cout << x << " " << y << endl;
		}
		else {
			int mem = tmp & (tmp - 1);
			int z = mem - (mem & (mem - 1));
			cnt[mask] = cnt[mask ^ x] + cnt[mask ^ y] + cnt[mask ^ z]
				- cnt[mask ^ x ^ y] - cnt[mask ^ x ^ z] - cnt[mask ^ y ^ z]
				+ cnt[mask ^ x ^ y ^ z] + lol[x ^ y ^ z];
			//cout << x << " " << y<< " " << z << endl;
		}
		/*cout << mask << " " << cnt[mask] << " ";
		for (int i = 0; i < N; i++)
			if ((1 << i) & mask)
				cout << (char)(i + 'a') << " ";
		cout << endl;*/
	}
	ll ans = 0;
	for (int mask = 0; mask < K; mask++) {
		ans ^= (n - cnt[all ^ mask]) * 1ll * (n - cnt[all ^ mask]);
	}
	cout << ans << endl;
	return;
}