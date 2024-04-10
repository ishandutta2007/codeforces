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

inline int toint(char c) {
	return c - 'a';
}

const int K = 26, N = 1e5 + 5;

struct Node {
	int next[K], go[K], link = -1, slink = -1, p = -1, pc;
	vector<int> leaf;
	Node (int p = -1, int ch = -1) : p(p), pc(ch) {
		for (int i = 0; i < K; i++) next[i] = go[i] = -1;
	}
};

vector<Node> trie(1);

int go(int v, int c);

int get_link(int v) {
	if (!~trie[v].link) {
		if (!v || !trie[v].p) {
			trie[v].link = 0;
		} else {
			trie[v].link = go(get_link(trie[v].p), trie[v].pc);
		}
	}
	return trie[v].link;
}

int go(int v, int c){
	if (!~trie[v].go[c]) {
		if (~trie[v].next[c]) {
			trie[v].go[c] = trie[v].next[c];
		} else {
			trie[v].go[c] = v == 0 ? 0 : go(get_link(v), c);
		}
	}
	return trie[v].go[c];
}

int get_slink(int v){
	if (!~trie[v].slink) {
		int nxt = get_link(v);
		if (!v || !nxt) {
			trie[v].slink = 0;
		} else if (trie[nxt].leaf.size()) {
			trie[v].slink = nxt;
		} else {
			trie[v].slink = get_slink(nxt);
		}
	}
	return trie[v].slink;
}

int n, q[N];
string s[N], match;
vector<int> pos[N];

void addstring(int id) {
	int v = 0;
	for (auto ch : s[id]) {
		int c = toint(ch);
		if (!~trie[v].next[c]) {
			trie[v].next[c] = trie.size();
			trie.emplace_back(v, c);
		}
		v = trie[v].next[c];
	}
	trie[v].leaf.emplace_back(id);
}

void get_suff(int v, int i) {
	while (v) {
		for (auto x : trie[v].leaf) {
			pos[x].push_back(i - (int) s[x].size() + 1);
		}
		v = get_slink(v);
	}
}

void Hollwo_Pelw() {
	cin >> match >> n;
	for (int i = 1; i <= n; i++)
		cin >> q[i] >> s[i], addstring(i);
	int r = 0;
	for (int i = 0; i < match.size(); i++){
		r = go(r, toint(match[i])), get_suff(r, i);
	}

	for (int i = 1; i <= n; i++){
		if (pos[i].size() < q[i]) {
			cout << "-1\n";
		} else {
			int ans = 2e9;
			for (int j = q[i] - 1; j < pos[i].size(); j++) {
				ans = min(ans, pos[i][j] - pos[i][j - q[i] + 1] + (int) s[i].size());
			}
			cout << ans << "\n";
		}
	}
}