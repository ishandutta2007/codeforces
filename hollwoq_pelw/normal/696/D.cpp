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

const int N = 205, K = 26;

inline const int toint(char c) { return c == '$' ? -1 : c - 'a'; }

struct node_t {
	int nxt[K], go[K], link, p, pc;

	int leaf, cnt;
	
	node_t(int _p = -1, int _c = -1)
		: p(_p), pc(_c) { clear(); }

	inline void clear() {
		memset(go, -1, sizeof go), memset(nxt, -1, sizeof nxt);
		link = -1, leaf = 0, cnt = -1;
	}

} tr[N];

int n, nnode = 0, a[N];

struct Aho_Corasick {

	inline void add_string(const string& s, int v = 1) {
		int p = 0;
		for (auto ch : s) {
			int c = toint(ch);

			if (tr[p].nxt[c] == -1) {
				tr[p].nxt[c] = ++ nnode;
				tr[nnode] = node_t(p, c);
			}

			p = tr[p].nxt[c];
		}

		tr[p].leaf += v;
	}

	inline int get_link(int v) {
		if (tr[v].link == -1) {

			if (v == 0 || tr[v].p == 0)
				tr[v].link = 0;
			else
				tr[v].link = go(get_link(tr[v].p), tr[v].pc);

		}
		return tr[v].link;
	}

	inline int go(int v, int c) {
		if (tr[v].go[c] == -1) {

			if (tr[v].nxt[c] != -1)
				tr[v].go[c] = tr[v].nxt[c];
			else
				tr[v].go[c] = v == 0 ? 0 : go(get_link(v), c);

		}
		return tr[v].go[c];
	}

	Aho_Corasick() { clear(); }

	Aho_Corasick(const vector<string> &v) {
		clear(); for (auto s : v) add_string(s);
	}

	inline int get_cnt(int v) {
		if (tr[v].cnt == -1) {
			if (v == 0)
				tr[v].cnt = 0;
			else
				tr[v].cnt = tr[v].leaf + get_cnt(get_link(v));
		}

		return tr[v].cnt;
	}

	void clear() {	
		while (nnode >= 0)
			tr[nnode --].clear();
		nnode = 0;
	}
} aho;

int64_t l;
string s;

struct matrix {
	int64_t a[N][N];

	int64_t* operator [] (int x) { return a[x]; }
	const int64_t* operator [] (int x) const { return a[x]; }

	matrix() {
		for (int i = 0; i <= nnode; i++)
			for (int j = 0; j <= nnode; j++)
				a[i][j] = -1e18;
	}

	matrix operator * (const matrix& b) const {
		matrix res;
		for (int i = 0; i <= nnode; i++)
			for (int j = 0; j <= nnode; j++) {
				for (int k = 0; k <= nnode; k++)
					res[i][j] = max(res[i][j], a[i][k] + b[k][j]);
			}
		return res;
	}
};

matrix binpow(matrix a, int64_t b) {
	matrix r;
	for (int i = 0; i <= nnode; i++)
		r[i][i] = 0;

	while (b) {
		if (b&1) r = r * a;
		b >>= 1; a = a * a;
	}

	return r;
}

void Hollwo_Pelw() {
	cin >> n >> l;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> s, aho.add_string(s, a[i]);

	matrix base;
	for (int i = 0; i <= nnode; i++)
		for (int j = 0; j < 26; j++) {
			int k = aho.go(i, j);
			base[i][k] = aho.get_cnt(k);
		}

	base = binpow(base, l);

	// for (int i = 0; i <= nnode; i++)
	// 	for (int j = 0; j <= nnode; j++)
	// 		cout << base[i][j] << " \n"[j == nnode];
	
	int64_t res = 0;
	for (int i = 0; i <= nnode; i++)
		res = max(res, base[0][i]);
	cout << res;
}