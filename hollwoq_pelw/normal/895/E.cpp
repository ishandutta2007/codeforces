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

const int N = 1e5 + 5;

int n, q, a[N];
double st[N << 2], lzadd[N << 2], lzmul[N << 2];

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

void apply(int id, int tl, int tr, double add, double mul){
	st[id] = mul * st[id] + add * ((double) tr - tl + 1);
	lzadd[id] = mul * lzadd[id] + add, lzmul[id] *= mul;
}

void push(int id, int tl, int tr){
	apply(left, lzadd[id], lzmul[id]);
	apply(right, lzadd[id], lzmul[id]);
	lzmul[id] = 1, lzadd[id] = 0;
}

void build(int id = 1, int tl = 1, int tr = n){
	lzmul[id] = 1;
	if (tl == tr) {
		st[id] = a[tl];
		return ;
	}
	build(left), build(right);
	st[id] = st[id << 1] + st[id << 1 | 1];
}

void upd(int l, int r, double add, double mul, int id = 1, int tl = 1, int tr = n){
	if (tl > r || l > tr) return ;
	if (l <= tl && tr <= r) return apply(id, tl, tr, add, mul);
	push(id, tl, tr), upd(l, r, add, mul, left), upd(l, r, add, mul, right);
	st[id] = st[id << 1] + st[id << 1 | 1];
}

double query(int l, int r, int id = 1, int tl = 1, int tr = n){
	if (tl > r || l > tr) return 0;
	if (l <= tl && tr <= r) return st[id];
	push(id, tl, tr);
	return query(l, r, left) + query(l, r, right);
}

#undef tm
#undef left
#undef right

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	build();
	for (int _ = 0, type, l1, r1, l2, r2; _ < q; _++){
		cin >> type >> l1 >> r1;
		if (type == 1) {
			cin >> l2 >> r2;
			double avg1 = query(l1, r1) / (double) (r1 - l1 + 1);
			double avg2 = query(l2, r2) / (double) (r2 - l2 + 1);
			upd(l1, r1, avg2 / (double) (r1 - l1 + 1), (double) (r1 - l1) / (double) (r1 - l1 + 1));
			upd(l2, r2, avg1 / (double) (r2 - l2 + 1), (double) (r2 - l2) / (double) (r2 - l2 + 1));
		} else {
			cout << fixed << setprecision(6) << query(l1, r1) << "\n";
		}
	}
}