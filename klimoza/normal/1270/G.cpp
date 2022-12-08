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
const double eps = 1e-8;
const ll inf0 = 1023 * 1024 * 1024;
const ll inf = inf0 * inf0;
//const ll mod = 1e9 + 9;
const ll mod = 998244353;
const ll mod2 = mod * mod;

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

const int N = 1e6 + 7;

int p[N], nxt[N];

void solve() {
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		fill(p, p + n + 1, -1);
		fill(nxt, nxt + n + 1, -1);
		for (int i = 1; i <= n; i++) {
			int t; cin >> t;
			nxt[i] = i - t;
		}
		int cur = 1;
		vector<int> ans;
		int d = -1;
		p[1] = 0;
		int cnt = 0;
		while (true) {
			ans.push_back(cur);
			if (p[nxt[cur]] != -1) {
				d = nxt[cur];
				cnt = p[cur] - p[d];
				break;
			}
			p[nxt[cur]] = p[cur] + 1;
			cur = nxt[cur];
		}
		reverse(all(ans));
		cout << cnt + 1 << endl;
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
			if (ans[i] == d) break;
		}
		cout << endl;
	}
	return;
}