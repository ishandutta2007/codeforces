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

struct node {
	int l, r, s;
	node (int x = 0)
		: l(x), r(x), s(x) {}
	node (int _l, int _r, int _s)
		: l(_l), r(_r), s(_s) {}
	friend node merge(node l, node r) {
		return node{max(l.l, r.l + l.s), max(r.r, l.r + r.s), l.s + r.s};
	}
} st[N << 2];

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

int n, res[N];

void update(int p, int x, int id = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		return st[id] = node(x), (void) 0;
	(p > tm ? update(p, x, right)
			: update(p, x, left));
	st[id] = merge(st[id << 1], st[id << 1 | 1]);
}

node query(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (l > r || tl > r || l > tr) return node();
	if (l <= tl && tr <= r) return st[id];
	return merge(query(l, r, left), query(l, r, right));
}

vector<int> v[N];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, x; i <= n; i++)
		cin >> x, v[x].push_back(i);
	{
		for (int i = 1; i <= n; i++) update(i, 1);
		for (int i = 1; i <= n; i++) {
			for (auto p : v[i])
				res[p] = max(res[p], query(1, p - 1).r + query(p + 1, n).l + 1 >> 1);
			for (auto p : v[i]) update(p, -1);
		}
	}
	{
		for (int i = 1; i <= n; i++) update(i, 1);
		for (int i = n; i >= 1; i--) {
			for (auto p : v[i])
				res[p] = max(res[p], query(1, p - 1).r + query(p + 1, n).l >> 1);
			for (auto p : v[i]) update(p, -1);
		}
	}
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
}