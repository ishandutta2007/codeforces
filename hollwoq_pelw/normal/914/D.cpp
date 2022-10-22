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

const int N = 5e5 + 5;

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

int st[N << 2], n, q;

void upd(int p, int x, int id = 1, int tl = 1, int tr = n) {
	if (tl == tr) {
		st[id] = x;
	} else {
		if (p > tm)
			upd(p, x, right);
		else
			upd(p, x, left);
		st[id] = __gcd(st[id << 1], st[id << 1 | 1]);
	}
}

struct node {
	int id, tl, tr;
};

vector<node> listid;

void get_query(int l, int r, int x, int id = 1, int tl = 1, int tr = n) {
	if (l > tr || tl > r) return ;
	if (l <= tl && tr <= r) {
		// cout << id << ' ' << tl << ' ' << tr << ' ' << st[id] << endl;
		if (st[id] % x != 0)
			listid.push_back({id, tl, tr});
		return ;
	}
	get_query(l, r, x, left), get_query(l, r, x, right);
}

bool process(int x, int id, int tl, int tr) {
	if (tl == tr) return 1;
	if (st[id << 1] % x != 0) {
		if (st[id << 1 | 1] % x != 0)
			return 0;
		return process(x, left);
	}
	return process(x, right);
}

void query(int l, int r, int x){
	listid.clear(), get_query(l, r, x);

	if (listid.size() >= 2) {
		cout << "NO\n";
	} else if (listid.empty()) {
		cout << "YES\n";
	} else {
		node y = listid.back();
		if (process(x, y.id, y.tl, y.tr))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}

#undef tm
#undef left
#undef right

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, x; i <= n; i++)
		cin >> x, upd(i, x);
	cin >> q;
	for (int i = 1, t, x; i <= q; i++){
		cin >> t;
		if (t == 1) {
			int l, r;
			cin >> l >> r >> x;
			query(l, r, x);
		} else {
			int p; cin >> p >> x; upd(p, x);
		}
	}
}