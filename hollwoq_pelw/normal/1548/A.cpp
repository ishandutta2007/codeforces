/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

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

int n, m, q, a[N], cnt[N], deg[N], res;

int ok(int id) {
	return !cnt[id];
}

void add(int u, int v) {
	res -= ok(u) + ok(v);
	cnt[min(u, v)] ++;
	res += ok(u) + ok(v);
}

void del(int u, int v) {
	res -= ok(u) + ok(v);
	cnt[min(u, v)] --;
	res += ok(u) + ok(v);	
}

void Hollwo_Pelw() {
	cin >> n >> m, res = n;
	for (int i = 1, u, v; i <= m; i++) {
		cin >> u >> v, add(u, v);
	}
	cin >> q;
	for (int i = 1, t, u, v; i <= q; i++) {
		cin >> t;
		if (t == 3)
			cout << res << '\n';
		else {
			cin >> u >> v;
			(t == 1 ? add(u, v) : del(u, v));
		}
	}
}