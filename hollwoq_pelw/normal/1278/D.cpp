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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 5e5 + 5;

int n, par[N], cnt;

inline int find(int u) {
	return par[u] = par[u] == u ? u : find(par[u]);
}

inline bool merge(int u, int v) {
	if ((u = find(u)) == (v = find(v)))
		return 0;
	return par[u] = v, 1;
}

pair<int, int> p[N];

void Hollwo_Pelw() {
	cin >> n, iota(par + 1, par + n + 1, 1);
	for (int i = 1; i <= n; i++)
		cin >> p[i].first >> p[i].second;
	sort(p + 1, p + n + 1);
	set<pair<int, int>> st;
	for (int i = 1; i <= n; i++) {
		while (!st.empty() && st.begin() -> first < p[i].first)
			st.erase(st.begin());
		for (auto it = st.begin(); it != st.end() && it -> first <= p[i].second; ++ it) {
			if (!merge(it -> second, i) || (++ cnt) >= n)
				return cout << "NO", (void) 0;
		}
		st.emplace(p[i].second, i);
	}
	cout << (cnt == n - 1 ? "YES" : "NO");
}