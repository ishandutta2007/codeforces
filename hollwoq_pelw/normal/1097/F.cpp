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

const int N = 1e5 + 5, K = 7007;

bitset<K> a[N], ini[K], que[K], p;

// g(1) = f(1) - f(2) - f(3) - f(5) + f(2 * 3) + f(2 * 5) + f(3 * 5) - f(2 * 3 * 5)
// check only numbers = p1 * p2 * p3 ...

void Hollwo_Pelw() {
	p.set();
	for (int i = 2; i * i < K; i++)
		for (int j = 1; j * i * i < K; j++)
			p[j * i * i] = 0;
	for (int i = 1; i < K; i++) {
		for (int j = i; j < K; j += i) 
			ini[j][i] = 1, que[i][j] = p[j / i];
	}

	int n, q; cin >> n >> q;
	for (int t, id, l, r, v; q--; ) {
		cin >> t >> id;
		if (t == 1 || t == 4) {
			cin >> v;
			if (t == 1) {
				a[id] = ini[v];
			}
			else {
				cout << ((a[id] & que[v]).count() & 1);
			}
		} else {
			cin >> l >> r;
			if (t == 2) {
				a[id] = a[l] ^ a[r];
			}
			else {
				a[id] = a[l] & a[r];
			}
		}
	}
}