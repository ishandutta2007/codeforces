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

const int N = 1e5 + 5;

const string t = "abc";

struct node_t {
	int ok[3][3];

	node_t () {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				ok[i][j] = i > j ? 1e9 : 0;
	}

	node_t (int v) {
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++) {
				ok[i][j] = i > j ? 1e9 : 0;
				if (i <= v && v <= j)
					ok[i][j] = 1;
			}
	}

	inline int get() {
		int res = 1e9;
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
				res = min(res, ok[i][j]);
		return res;
	}

	int * operator [] (int x) { return ok[x]; }
	const int * operator [] (int x) const { return ok[x]; }

	friend node_t operator + (const node_t &a, const node_t &b) {
		node_t c;
		for (int i = 0; i < 3; i++) {
			for (int j = i; j < 3; j++) {
				c[i][j] = 1e9;
				for (int k = i; k < j; k++)
					c[i][j] = min(c[i][j], a[i][k] + b[k + 1][j]);
				for (int k = i; k <= j; k++)
					c[i][j] = min(c[i][j], a[i][k] + b[k][j]);
			}
		}
		return c;
	}
} st[N << 2];

string s;
int n, q;

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

void build(int id = 1, int tl = 0, int tr = n + 1) {
	if (tl == tr) {
		st[id] = node_t(s[tl] - 'a');
		return ;
	}
	build(left), build(right);
	st[id] = st[id << 1] + st[id << 1 | 1];
}

void update(int p, char c, int id = 1, int tl = 0, int tr = n + 1) {
	if (tl == tr) {
		st[id] = node_t(c - 'a');
		return ;
	}
	(p > tm ? update(p, c, right)
			: update(p, c, left));
	st[id] = st[id << 1] + st[id << 1 | 1];
}

void Hollwo_Pelw() {
	cin >> n >> q >> s;
	s = "c" + s + "a";

	build();

	for (int p; q --; ) {
		char c; cin >> p >> c;
		update(p, c);
	
		cout << st[1][0][2] << '\n';
	}
}