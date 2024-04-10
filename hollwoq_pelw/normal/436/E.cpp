/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
		freopen(fileerr.c_str(), "w", stderr);
#endif
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	FAST_IO("input.inp", "output.out", "error.err");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

#define int long long

const int N = 3e5 + 5;

set<pair<int, int>> p, q;

int n, m, res[N], a[N << 1], vis[N << 1], ans;

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 0, x, y; i < n; i++) {
		cin >> x >> y;
		a[i + 0] = x - 0;
		a[i + n] = y - x;
		p.emplace(x, i);
		q.emplace(y, i);
	}
	while (m --) {
		while (p.size() && vis[p.begin() -> second]) p.erase(p.begin());
		while (q.size() && vis[q.begin() -> second]) q.erase(q.begin());

		int i = p.begin() -> second; p.erase(p.begin());
		
		while (p.size() && vis[p.begin() -> second]) p.erase(p.begin());
		
		if (m && q.size() && (a[i] + p.begin() -> first) >= q.begin() -> first) {
			p.emplace(a[i], i);
			i = q.begin() -> second; q.erase(q.begin());
		}

		if (i < n) {
			p.emplace(a[i + n], i + n);
		}

		ans += a[i];
		res[i % n] ++, vis[i] = 1;
	}

	cout << ans << '\n';
	for (int i = 0; i < n; i++)
		cout << res[i];
}