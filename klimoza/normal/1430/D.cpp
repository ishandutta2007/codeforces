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

mt19937 mrand(random_device{}());

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

void solve() {
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s; cin >> s;
		vector<int> cnt;
		int cur = 0;
		for (int i = 0; i < n; i++) {
			if (i && s[i] != s[i - 1]) {
				cnt.push_back(cur);
				cur = 0;
			}
			cur++;
		}
		cnt.push_back(cur);
		int l = 0;
		set<int> f;
		n = cnt.size();
		for (int i = 0; i < n; i++)
			f.insert(i);
		int ans = 0;
		while (true) {
			bool fl = false;
			while (!f.empty()) {
				if (cnt[*f.begin()] < 2)
					f.erase(f.begin());
				else {
					cnt[*f.begin()]--;
					fl = true;
					break;
				}
			}
			while (l < n && !cnt[l])
				l++;
			if (l == n)
				break;
			//cout << ans << " " << l << endl;
			if (!fl)
				cnt[l]--;
			ans++;
			while (l < n && !cnt[l])
				l++;
			if (l == n)
				break;
			cnt[l] = 0;
		}
		cout << ans << endl;
	}
	return;
}