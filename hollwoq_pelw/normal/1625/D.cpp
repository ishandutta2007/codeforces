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

const int N = 3e5 + 5;

int n, k, a[N], tr[N * 30][2], leaf[N * 30], nnode;
map<int, vector<int>> mp;
vector<int> res;

inline void solve(vector<int> &id) {
	for (int i = 0; i <= nnode; i++)
		tr[i][0] = tr[i][1] = 0;
	nnode = 0;

	for (auto i : id) {
		if (nnode) {
			int p = 0, cur = 0;
			for (int b = 30; b --; ) {
				int c = a[i] >> b & 1;
				if (tr[p][c ^ 1])
					cur ^= 1 << b, c ^= 1;
				p = tr[p][c];
			}
			if (cur >= k) {
				res.push_back(i);
				res.push_back(leaf[p]);
				return ;
			}
		}
		{
			int p = 0;
			for (int b = 30; b --; ) {
				int c = a[i] >> b & 1;
				if (!tr[p][c])
					tr[p][c] = ++ nnode;
				p = tr[p][c];
			}
			leaf[p] = i;
		}
	}

	if (id.size())
		res.push_back(id[0]);
}

void Hollwo_Pelw() {
	cin >> n >> k;
	if (!k) {
		cout << n << '\n';
		for (int i = 1; i <= n; i++)
			cout << i << ' ';
		return ;
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int lg = __lg(k);

	for (int i = 1; i <= n; i++)
		mp[a[i] >> (lg + 1)].push_back(i);

	for (auto [p, v] : mp)
		solve(v);

	if (res.size() < 2)
		return cout << "-1\n", (void) 0;
	cout << res.size() << '\n';
	for (auto v : res) cout << v << ' ';
}