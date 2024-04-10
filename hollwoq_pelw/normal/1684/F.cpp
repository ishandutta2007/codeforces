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

const int N = 2e5 + 5;

int n, m, a[N], rp[N];
vector<int> upd[N];

void Hollwo_Pelw(){
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i], rp[i] = 0;
	for (int l, r; m --; ) {
		cin >> l >> r;
		rp[l] = max(rp[l], r);
	}
	for (int i = 1; i <= n; i++) {
		rp[i] = max(rp[i - 1], rp[i]);
	}

	for (int i = 1; i <= n; i++)
		upd[i].clear();

	map<int, vector<int>> mp;
	for (int i = 1; i <= n; i++)
		mp[a[i]].push_back(i);

	multiset<int> st;

	for (auto &[v, p] : mp) {
		int l1 = n, l2 = n, r1 = 0, r2 = 0;
		for (int i = 0; i < (int) p.size(); i++) {
			if (rp[p[i]] < p[i]) continue ;
			int j = upper_bound(p.begin(), p.end(), rp[p[i]]) - p.begin() - 1;

			if (j <= i) continue ;

			l1 = min(l1, p[i]);
			r1 = max(r1, p[j]);
			l2 = min(l2, p[i + 1]);
			r2 = max(r2, p[j - 1]);
		}
		if (l1 > r1) continue;

		st.insert(r2);
		if (rp[l1] < r1) {
			upd[l2].push_back(-r2);
		} else {
			upd[l1].push_back(-r2);
			upd[l1].push_back(+r1);
			upd[l2].push_back(-r1);
		}
	}

	if (st.empty()) {
		cout << 0 << '\n';
		return ;
	}

	int res = 1e9, sz = st.size();
	for (int i = 1; i <= n; i++) {
		if ((int)st.size() == sz)
			res = min(res, *st.rbegin() - i + 1);
		for (auto x : upd[i]) {
			if (x < 0)
				st.erase(st.find(-x));
			else
				st.insert(x);
		}
	}

	cout << res << '\n';
}