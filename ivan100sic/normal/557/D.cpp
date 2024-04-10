#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, m;
basic_string<int> e[100005];
bool loshe;
int cnt[5], cl[100005];

void dfs(int x) {
	cnt[cl[x]]++;
	for (int y : e[x]) {
		if (cl[y]) {
			if (cl[x] == cl[y])
				loshe = true;
		} else {
			cl[y] = 3 - cl[x];
			dfs(y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}
	
	if (m == 0) {
		cout << "3 " << n*(n-1ll)*(n-2) / 6 << '\n';
		return 0;
	}
	
	// max degree = 1?
	int md = 0;
	for (int i=1; i<=n; i++) {
		md = max(md, (int)e[i].size());
	}
	
	if (md == 1) {
		cout << "2 " << m*(n-2ll) << '\n';
		return 0;
	}
	
	ll sol = 0;
	for (int i=1; i<=n; i++) {
		if (!cl[i]) {
			memset(cnt, 0, sizeof cnt);
			cl[i] = 1;
			dfs(i);
			if (loshe) {
				cout << "0 1\n";
				return 0;
			} else {
				sol += cnt[1] * (cnt[1]-1ll) / 2;
				sol += cnt[2] * (cnt[2]-1ll) / 2;
			}
		}
	}
	
	cout << "1 " << sol << '\n';
}