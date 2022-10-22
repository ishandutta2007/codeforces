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

const int N = 2e5 + 5;

int n, m, cnt1, cnt2;

map<pair<int, int>, char> ed;

void add(int u, int v, char c) {
	ed[{u, v}] = c;
	if (ed.count({v, u})) {
		++ cnt2;
		if (ed[{v, u}] == ed[{u, v}])
			++ cnt1;
	}
}

void del(int u, int v) {
	if (ed.count({v, u})) {
		-- cnt2;
		if (ed[{v, u}] == ed[{u, v}])
			-- cnt1;
	}
	ed.erase({u, v});
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		char t, c; int u, v;
		cin >> t;
		if (t == '+') {
			cin >> u >> v >> c, add(u, v, c);
		} else if (t == '-') {
			cin >> u >> v, del(u, v);
		} else {
			cin >> u, cout << ((u & 1 ? cnt2 : cnt1) ? "YES\n" : "NO\n");
		}
	}
}