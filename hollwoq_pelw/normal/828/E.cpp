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

const int N = 1e5 + 5;

int n, q;
string s;

struct fenwick_tree {
	int bit[N];

	void add(int x, int v) {
		for (; x <= n; x += x & -x)
			bit[x] += v;
	}

	int _query(int x) {
		int r = 0;
		for (; x; x -= x & -x)
			r += bit[x];
		return r;
	}

	int query(int l, int r) {
		return _query(r) - _query(l - 1);
	}

} bit[15][15][4];

inline int comp(char c) {
	return (c > 'A') + (c > 'C') + (c > 'G');
}

void Hollwo_Pelw() {
	cin >> s >> q, n = s.size(), s = '$' + s;
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= n; j++)
			bit[i][j % i][comp(s[j])].add(j, 1);
	for (int _ = 0, t; _ < q; _++) {
		cin >> t;
		if (t == 1) {
			int p; char c;
			cin >> p >> c;
			
			for (int i = 1; i <= 10; i++) {
				bit[i][p % i][comp(s[p])].add(p, -1);
				bit[i][p % i][comp(c)].add(p, 1);
			}
			s[p] = c;

		} else {
			int l, r; string e;
			cin >> l >> r >> e;
			
			int ans = 0, sz = e.size();
			for (int i = 0; i < sz; i++)
				ans += bit[sz][(l + i) % sz][comp(e[i])].query(l, r);
			cout << ans << '\n';
		}
	}
}