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
	cout << "\nExcution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

#define int long long

const int N = 1e5 + 5;

int n, a[N], b[N], vis[N], nxt[N], siz;

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i <= n; i++) nxt[a[i]] = b[i], vis[i] = 0;

	vector<int> f;

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			vis[i] = 1, siz = 1;
			for (int u = i; nxt[u] != i; )
				u = nxt[u], siz ++, vis[u] = 1;
			f.push_back(siz / 2);
		}
	}

	int l = 1, r = n, res = 0;

	for (int x : f) {
		vector<int> c;
		while (x --) {
			c.push_back(l ++);
			c.push_back(r --);
		}
		for (int i = 0; i < (int) c.size(); i++)
			res += abs(c[i] - c[(i + 1) % c.size()]);
	}

	cout << res << '\n';
}