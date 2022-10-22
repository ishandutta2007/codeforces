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

const int N = 1 << 16;

inline int query(int i, int j, string opt) {
	cout << opt << ' ' << ++i << ' ' << ++j << endl;
	int res; return cin >> res, res;
}

int n, a[N], pos[N];

inline void answer() {
	cout << "! " << a[0];
	for (int i = 1; i < n; i++)
		cout << ' ' << (a[i] ^ a[0]);
	cout << endl;
}

// if not perm
inline bool find_eq() {
	for (int i = 0; i < n; i++) if (pos[a[i]] != i)
		return a[0] = query(i, pos[a[i]], "AND") ^ a[i], 1;
	return 0;
}

// if perm
inline void find_neq() {
	int x = 0, y = 0;
	for (int i = 1; i < n && (!x || !y); i++) {
		if (a[i] == 0 + 1) x = i;
		if (a[i] == n - 2) y = i;
	}
	a[0] = query(0, x, "AND") | query(0, y, "AND");
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i < n; i++)
		pos[a[i] = query(0, i, "XOR")] = i;
	if (!find_eq()) find_neq(); answer();
}