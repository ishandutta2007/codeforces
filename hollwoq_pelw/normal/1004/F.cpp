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

const int N = 1e5 + 5;

#define v first
#define p second

void merge(vector<pair<int, int>> &r, const vector<pair<int, int>> &a, const vector<pair<int, int>> &b) {
	if (a.empty() && b.empty()) return ;
	r = a.empty() ? vector<pair<int, int>>(1, {b[0].v, 0}) : a;
	for (auto x : b) {
		int v = r.back().v | x.v;
		if (v == r.back().v)
			r.back().p += x.p;
		else
			r.emplace_back(v, x.p);
	}
}

int n, q, x, t, a, b;

struct node {
	long long res = 0;
	vector<pair<int, int>> l, r;
	node () {}
	node (int v) {
		l = r = {{v, 1}}, res = v >= x;
	}
	node operator + (const node &o) {
		node v; v.res = res + o.res;
		merge(v.l, l, o.l), merge(v.r, o.r, r);
		for (int i = 0, j = o.l.size(), cnt = 0; i < r.size(); i++) {
			while (j && (r[i].v | o.l[j - 1].v) >= x)
				cnt += o.l[-- j].p;
			v.res += 1ll * r[i].p * cnt;
		}
		return v;		
	}
} st[N << 2];

#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

void build(int id = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		return cin >> b, st[id] = node(b), (void) 0;
	int tm = tl + tr >> 1;
	build(left), build(right);
	st[id] = st[id << 1] + st[id << 1 | 1];
}

void update(int id = 1, int tl = 1, int tr = n) {
	if (tl == tr)
		return st[id] = node(b), (void) 0;
	int tm = tl + tr >> 1;
	(a > tm ? update(right) : update(left));
	st[id] = st[id << 1] + st[id << 1 | 1];
}

node query(int id = 1, int tl = 1, int tr = n) {
	if (a > tr || tl > b) return node();
	if (a <= tl && tr <= b) return st[id];
	int tm = tl + tr >> 1;
	return query(left) + query(right);
}

void Hollwo_Pelw() {
	cin >> n >> q >> x, build();
	while (q--) {
		cin >> t >> a >> b;
		if (t == 1)
			update();
		else
			cout << query().res << '\n';
	}
}