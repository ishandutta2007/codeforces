#include <bits/stdc++.h>

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	std::vector<int> nxt(n);
	for (int i = 0; i < n; ++i) {
		std::cin >> a[i];
		nxt[i] = (i + 1) % n;
	}
	std::vector<bool> vis(n);
	std::vector<int> Q;
	for (int i = 0; i < n; ++i) {
		if (std::__gcd(a[i], a[nxt[i]]) == 1) {
			Q.push_back(i);
		}
	}
	std::vector<int> ans;
	for (int k = 0; k < (int)Q.size(); ++k) {
		int i = Q[k];
		if (vis[i]) {
			continue;
		}
		vis[nxt[i]] = true;
		ans.push_back(nxt[i]);
		nxt[i] = nxt[nxt[i]];
		if (std::__gcd(a[i], a[nxt[i]]) == 1) {
			Q.push_back(i);
		}
	}
	std::cout << ans.size();
	for (int v : ans) {
		std::cout << " " << v + 1;
	}
	std::cout << "\n";
}

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);

	int T;
	std::cin >> T;
	while (T--) {
		solve();
	}
}