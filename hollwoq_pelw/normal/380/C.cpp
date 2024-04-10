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
    FAST_IO("hollwo_pelw_train.inp", "hollwo_pelw_train.out");
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

const int N = 1e6 + 6;

struct node {
	int len = 0, cl = 0, op = 0;
	node () {}
	node (char c) {
		cl = c == ')', op = c == '(';
	}
	friend node operator + (node l, node r) {
		int x = min(l.op, r.cl);
		node res;
		res.len = l.len + r.len + x;
		res.cl = l.cl + r.cl - x;
		res.op = l.op + r.op - x;
		return res;
	}
} st[N << 2];

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

int n, q;
string s;

void build(int id = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		st[id] = node(s[tl - 1]);
		return ;
	}
	build(left), build(right);
	st[id] = st[id << 1] + st[id << 1 | 1];
}

node query(int l, int r, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return node();
	if (l <= tl & tr <= r) return st[id];
	return query(l, r, left) + query(l, r, right); 
}

void Hollwo_Pelw() {
	cin >> s >> q;
	n = s.size();
	build();
	for (int i = 0, l, r; i < q; i++) {
		cin >> l >> r;
		cout << query(l, r).len * 2 << '\n';
	}
}