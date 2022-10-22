#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen(".inp", "r"))
		assert(freopen(".inp", "r", stdin)), assert(freopen(".out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 505;

int n, a[N], b[N], adj[N][N];

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];
	if (a[1] != b[1] || a[n] != b[n])
		return cout << "NO\n", (void) 0;
	
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		adj[i][j] = 0;

	for (int i = 1; i < n; i++) {
		adj[a[i]][a[i + 1]] ++;
		adj[a[i + 1]][a[i]] ++;
	}
	for (int i = 1; i < n; i++) {
		adj[b[i]][b[i + 1]] --;
		adj[b[i + 1]][b[i]] --;
	}
	
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++)
		if (adj[i][j]) return cout << "NO\n", (void) 0;

	vector<pair<int, int>> res;

	auto do_opt = [&](int l, int r) {
		res.emplace_back(l, r);
		reverse(a + l, a + r + 1);
	};

	auto find = [&](int i) -> int {
		int res = 0;
		for (int j = i; j < n; j++)  {
			if (a[j] == b[i] && a[j + 1] == a[i - 1]) {
				return do_opt(i - 1, j + 1), 0;
			}
			if (a[j] == a[i - 1] && a[j + 1] == b[i]) res = j;
		}
		return res;
	};

	auto rev = [&](int i, int p) {
		for (int l = i - 1; l <= p; l++)
			for (int r = p + 1; r <= n; r++)
				if (a[l] == a[r])
					return do_opt(l, r);
	};

	for (int i = 2; i < n; i++) if (a[i] != b[i]) {
		if (int p = find(i)) {
			rev(i, p);
			assert(find(i) == 0);
		}
	}

	cout << "YES\n" << res.size() << '\n';
	for (auto [l, r] : res)
		cout << l << ' ' << r << '\n';

}