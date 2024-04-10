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

const int N = 1e5 + 5, inf = 2e9;

#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

struct node {
	int64_t cnt, sum, res; 
	node (int64_t _cnt = 0, int64_t _sum = 0, int64_t _res = 0)
		: cnt(_cnt), sum(_sum), res(_res) {}
	friend node merge(const node &l, const node &r) {
		return node(
			l.cnt + r.cnt,
			l.sum + r.sum,
			l.res + r.res + r.sum * l.cnt - l.sum * r.cnt
		);
	}
} st[1 << 19 | 5];

vector<int> allp;

void update(int p, bool add, int id = 1, int tl = 0, int tr = allp.size() - 1) {
	if (tl == tr) {
		st[id] = add ? node(1, p, 0) : node();
	} else {
		int tm = tl + tr >> 1;
		(p > allp[tm] ? update(p, add, right)
					: update(p, add, left));
		st[id] = merge(st[id << 1], st[id << 1 | 1]);
	}
}

node query(int l, int r, int id = 1, int tl = 0, int tr = allp.size() - 1) {
	if (l > allp[tr] || allp[tl] > r) return node();
	if (l <= allp[tl] && allp[tr] <= r) return st[id];
	int tm = tl + tr >> 1;
	return merge(query(l, r, left), query(l, r, right));
}

struct Query {
	int t, x, y;
} qry[N];

int n, q, a[N];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], allp.push_back(a[i]);
	cin >> q;
	for (int i = 1, t, x, y; i <= q; i++) {
		cin >> t >> x >> y, qry[i] = {t, x, y};
		if (t == 1) a[x] += y, allp.push_back(a[x]);
	}
	
	sort(allp.begin(), allp.end());
	allp.erase(unique(allp.begin(), allp.end()), allp.end());
	
	for (int i = q; i; i--)
		if (qry[i].t == 1) a[qry[i].x] -= qry[i].y;
	
	for (int i = 1; i <= n; i++) update(a[i], 1);
	for (int i = 1; i <= q; i++) {
		if (qry[i].t == 1) {
			int p = qry[i].x, d = qry[i].y;
			update(a[p], 0);
			a[p] += d;
			update(a[p], 1);
		} else {
			int l = qry[i].x, r = qry[i].y;
			cout << query(l, r).res << '\n';
		}
	}
}