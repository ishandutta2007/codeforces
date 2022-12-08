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
#define pb(v) push_back(v)

#define endl '\n'

using namespace std;
typedef long long ll;
typedef long double ld;

mt19937 mrand(random_device{}());

double PI = acos((double)-1);
const ld eps = 1e-7;
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

const int N = 1e5 + 7;

vector<int> g[N];

bool fl = false;

bool isKek[N];

int dfs(int v, int last = -1) {
	bool b1 = false;
	bool b2 = false;
	for (int u : g[v]) {
		if (u == last) continue;
		if (dfs(u, v) & 1) b1 = true;
		else b2 = true;
	}
	if (b1 && b2) fl = true;
	if (b1) return 0;
	else return 1;
}

int ans;

void calc(int v, int last = -1) {
	int cnt = 0;
	for (int u : g[v]) {
		if (u == last) continue;
		calc(u, v);
		if (isKek[u]) cnt++;
	}
	ans -= max(0, (cnt - 1));
}

void solve() {
	int n; cin >> n;
	ans = n - 1;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for (int i = 0; i < n; i++) {
		if (g[i].size() == 1)
			isKek[i] = true;
	}
	int root = -1;
	for (int i = 0; i < n; i++) {
		if (g[i].size() > 1) {
			root = i;
			break;
		}
	}
	dfs(root);
	if (fl) cout << 3 << " ";
	else cout << 1 << " ";
	calc(root);
	cout << ans << endl;
    return;
}