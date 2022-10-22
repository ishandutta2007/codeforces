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

const int N = 2e5 + 5, K = 26;

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
int nnode = 0;

struct Aho_Corasick {

	inline void add_string(const string& s) {
		int p = 0;
		for (auto ch : s) {
			int c = toint(ch);

			if (tr[p].nxt[c] == -1) {
				tr[p].nxt[c] = ++ nnode;
				tr[nnode] = node_t(p, c);
			}

			p = tr[p].nxt[c];
		}

		tr[p].leaf ++;
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

	vector<int> work(const string &t) {
		vector<int> res(t.size());

		for (int i = 0, p = 0; i < t.size(); i++) {
			int c = toint(t[i]);

			p = go(p, c);
			res[i] = get_cnt(p);
		}

		return res;
	}

	void clear() {	
		while (nnode >= 0)
			tr[nnode --].clear();
		nnode = 0;
	}
};

void Hollwo_Pelw() {
	string t; cin >> t;
	
	int n; cin >> n;

	vector<string> st(n);
	for (auto &s : st) cin >> s;

	vector<int> res1, res2;
	
	// solve
	res1 = Aho_Corasick(st).work(t);

	reverse(t.begin(), t.end());
	for (auto &s : st)
		reverse(s.begin(), s.end());

	res2 = Aho_Corasick(st).work(t);
	reverse(res2.begin(), res2.end());

	int64_t res = 0;

	for (int i = 1; i < t.size(); i++)
		res += 1ll * res1[i - 1] * res2[i];

	cout << res;
}