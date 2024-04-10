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
	cin >> testcases;
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

const int N = 1e5 + 5;

int n, bit[N];
string s, t;

inline void add(int p, int v) {
	for (++ p; p <= n; p += p & -p)
		bit[p] += v;
}

inline int query(int p) {
	int r = 0;
	for (++ p; p > 0; p -= p & -p)
		r += bit[p];
	return r;
}

vector<int> pos[26];

void Hollwo_Pelw() {
	cin >> n >> s >> t;
	fill(bit + 1, bit + n + 1, 0);
	for (int i = 0; i < 26; i++)
		pos[i].clear();

	for (int i = 0; i < n; i++) {
		pos[s[i] - 'a'].push_back(i);
		add(i, 1);
	}

	for (int i = 0; i < 26; i++)
		reverse(pos[i].begin(), pos[i].end());

	int res = 1e18, cur = 0;
	for (int i = 0; i < n; i++) {
		// cout << "solve " << i << ' ' << cur << '\n';
		int c = t[i] - 'a';
		for (int j = 0; j < c; j++) if (pos[j].size()) {
			res = min(res, cur + query(pos[j].back() - 1));
			// cout << query(pos[j].back() - 1) << '\n';
		}
		if (pos[c].empty()) break ;
		cur += query(pos[c].back() - 1);
		add(pos[c].back(), -1);
		pos[c].pop_back();
	}

	cout << (res == 1e18 ? -1 : res) << '\n';
}