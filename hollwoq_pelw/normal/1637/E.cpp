/*
// is short or still long ???
hollwo_pelw's tecntlate(short)
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

const int N = 3e5 + 5;

map<int, int> cnt;
set<pair<int, int>> bad;
vector<int> val[N];

int n, m;

void Hollwo_Pelw() {
	cin >> n >> m;
	
	for (int i = 1, a; i <= n; i++)
		cin >> a, cnt[a] ++;

	for (auto [v, p] : cnt)
		val[p].push_back(v);

	for (int x, y; m --; ) {
		cin >> x >> y;
		bad.emplace(x, y);
		bad.emplace(y, x);
	}

	vector<int> sus;

	for (int i = 1; i <= n; i++)
		if (val[i].size()) {
			sus.push_back(i);
			sort(val[i].rbegin(), val[i].rend());
		}

	long long res = 0;

	for (auto p1 : sus) for (int v1 : val[p1])
		for (auto p2 : sus) for (int v2 : val[p2])
			if (!bad.count({v1, v2}) && v1 != v2) {
				res = max(res, 1ll * (v1 + v2) * (p1 + p2));
				break ;
			}

	cout << res << '\n';

	cnt.clear();
	bad.clear();

	for (auto p : sus) val[p].clear();
}