#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int maxn = (int)1e5 + 10, mod = (int)1e9 + 7;
vector <int> ed[maxn];
int dp[maxn][2];

void add(int &x, int y) {
	x += y;

	if (x >= mod) {
		x -= mod;
	}
}

void mul(int &a, int b) {
	a = (ll)a * b % mod;
}

void dfs(int v, int p) {
	int a = 1, b = 1;
	bool st = false;
	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			st = true;
			dfs(u, v);
			mul(a, dp[u][0]);
			mul(b, dp[u][1]);
		}
	}

	if (st) {
		add(a, b);
	}

	dp[v][0] = dp[v][1] = a;
}

int ans[maxn];

ll my_pow(ll a, ll b) {
	if (b == 0) {
		return 1;
	}

	if (b & 1) {
		return a * my_pow(a, b - 1) % mod;
	}

	ll z = my_pow(a, b >> 1);

	return z * z % mod;
}

int del(int a, int b) {
	return a * my_pow(b, mod - 2) % mod;
}

void go(int v, int p, int a, int b) {
	if (a >= mod) {
		a -= mod;
	}

	if (b >= mod) {
		b -= mod;
	}

	int x = a;
	int y = b;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			mul(x, dp[u][0]);
			mul(y, dp[u][1]);
		}
	}

	ans[v] = (x + y) % mod;

	for (int i = 0; i < (int)ed[v].size(); i++) {
		int u = ed[v][i];

		if (u != p) {
			int x1 = del(x, dp[u][0]);
			int y1 = del(y, dp[u][1]);

			if (!(v == 1 && (int)ed[v].size() == 1)) {
				go(u, v, x1 + y1, x1 + y1);
			} else {
				go(u, v, 1, 1);
			}
		}
	}
}

int main() {
	int n;

	cin >> n;

	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}

	for (int i = 0; i < n - 1; i++) {
		int x, y;

		scanf("%d %d", &x, &y);

		ed[x].push_back(y);
		ed[y].push_back(x);
	}

	dfs(1, -1);
	go(1, -1, 1, 1);

	int res = 0;

	for (int i = 1; i <= n; i++) {
		add(res, ans[i]);
	}

	cout << res << endl;

	return 0;
}