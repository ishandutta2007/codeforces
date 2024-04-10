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

#define int long long

const int N = 2e5 + 5;

int n, m, a[N];
vector<int> pos[N];

void Hollwo_Pelw(){
	cin >> n >> m;
	for (int i = 0; i <= n; i++)
		a[i] = 0, pos[i].clear();
	for (int i = 1, x; i <= n; i++)
		cin >> x, a[i] += x;
	for (int i = 1, x; i <= n; i++)
		cin >> x, a[i] -= x;
	for (int i = 1; i <= n; i++)
		a[i] += a[i - 1];
	for (int l, r; m --; ) {
		cin >> l >> r;
		pos[l - 1].push_back(r);
		pos[r].push_back(l - 1);
	}
	set<int> zer, non_zer;
	for (int i = 0; i <= n; i++) {
		if (a[i] == 0)
			zer.insert(i);
		else
			non_zer.insert(i);
	}
	while (!zer.empty()) {
		int u = *zer.begin(); zer.erase(zer.begin());
		int l = u, r = u;
		for (int v : pos[u]) {
			if (non_zer.count(v))
				continue;
			l = min(l, v);
			r = max(r, v);
		}
		while (1) {
			auto it = non_zer.lower_bound(l);
			if (it == non_zer.end() || *it > r)
				break;
			zer.insert(*it);
			non_zer.erase(it);
		}
	}
	if (non_zer.empty())
		cout << "YES\n";
	else
		cout << "NO\n";
}