#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const int MAXN = 65536;

struct tree {

	int lazy[2*MAXN], hi[2*MAXN];

	void push(int node) {
		if (lazy[node]) {
			hi[node] += lazy[node];
			if (node < MAXN) {
				lazy[2*node] += lazy[node];
				lazy[2*node+1] += lazy[node];
			}
			lazy[node] = 0;
		}
	}

	void reset() {
		for (int i=1; i<2*MAXN; i++) {
			lazy[i] = 0;
			hi[i] = 0;
		}
	}

	void update(int l, int r, int amount, int node=1, int nl=1, int nr=MAXN) {
		push(node);
		if (r < nl || nr < l) {
			return;
		}
		if (l <= nl && nr <= r) {
			lazy[node] += amount;
			return;
		}
		int m = (nl + nr) >> 1;
		update(l, r, amount, 2*node, nl, m);
		update(l, r, amount, 2*node+1, m+1, nr);
		push(2*node);
		push(2*node+1);
		hi[node] = max(hi[2*node], hi[2*node+1]);
	}

	int get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		push(node);
		if (r < nl || nr < l) {
			return 0;
		}
		if (l <= nl && nr <= r) {
			return hi[node];
		}
		int m = (nl + nr) >> 1;
		int vl = get(l, r, 2*node, nl, m);
		int vr = get(l, r, 2*node+1, m+1, nr);
		return max(vl, vr);
	}

};

int seen[35005];
int a[35005];
int dp[35005][55];
int n, k;

void unsee() {
	for (int i=1; i<=n; i++) {
		seen[i] = 0;
	}
}

tree drvo;

int main() {
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	{
		unsee();
		for (int i=1; i<=n; i++) {
			dp[i][1] = dp[i-1][1];
			if (!seen[a[i]]) {
				seen[a[i]] = i;
				dp[i][1]++;
			}
		}
	}

	for (int j=2; j<=k; j++) {
		drvo.reset();
		unsee();
		for (int i=1; i<=n; i++) {
			int x = a[i];
			drvo.update(seen[x]+1, i, 1);
			drvo.update(i, i, dp[i-1][j-1]);

			seen[x] = i;

			dp[i][j] = drvo.get(1, i);
		}
	}
/*
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=k; j++) {
			cerr << dp[i][j] << ' ';
		}
		cerr << '\n';
	}
*/
	cout << dp[n][k];
}