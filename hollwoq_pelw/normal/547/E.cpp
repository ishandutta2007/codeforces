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
	int nxt[K], go[K], slink, link, p, pc;

	int leaf;
	vector<int> v;
	
	node_t(int _p = -1, int _c = -1)
		: p(_p), pc(_c) { clear(); }

	inline void clear() {
		memset(go, -1, sizeof go), memset(nxt, -1, sizeof nxt);
		slink = link = -1, leaf = 0, v.clear();
	}

} tr[N];

int n, q, nnode = 0, pos[N];
string s[N];

struct Aho_Corasick {
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

	inline void clear() {	
		while (nnode >= 0)
			tr[nnode --].clear();
		nnode = 0;
	}

	Aho_Corasick() { clear(); }

	inline int get_slink(int v) {
		if (tr[v].slink == -1) {
			int nxt = get_link(v);
			if (v == 0 || tr[v].p == 0)
				tr[v].slink = 0;
			else if (tr[nxt].leaf)
				tr[v].slink = nxt;
			else
				tr[v].slink = get_slink(nxt);
		}

		return tr[v].slink;
	}

	void work(const string& s, int id) {
		int p = 0;
		for (char ch : s) {
			int c = toint(ch);

			p = go(p, c);

			int cp = p;
			while (cp) {
				tr[cp].v.push_back(id);
				cp = get_slink(cp);
			}
		}
	}

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

		tr[p].leaf = v;
		pos[v] = p;
	}
} aho;

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> s[i], aho.add_string(s[i], i);
	
	for (int i = 1; i <= n; i++)
		aho.work(s[i], i);

	for (int l, r, k; q --; ) {
		cin >> l >> r >> k; auto &v = tr[pos[k]].v;
		cout << upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l) << '\n';
	}
}