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

const int N = 5e5 + 5, mod = 998244353;

inline int add(int a, int b) {
	return a + b >= mod ? a + b - mod : a + b;
}

inline void sadd(int &a, int b) {
	a = a + b >= mod ? a + b - mod : a + b;
}

inline int mul(int a, int b) {
	return 1ll * a * b % mod;
}

inline int mul(int a, int b, int c) {
	return mul(mul(a, b), c);
}

#define tm (tl + tr >> 1)
#define left id << 1, tl, tm
#define right id << 1 | 1, tm + 1, tr

int n, q, a[N];

struct node {
	int v[4], len;
} st[N << 2];

node merge(node a, node b, int ra, int lb) {
	node c;
	int x = a.len == 1 ? 0 : 1;
	int y = b.len == 1 ? 0 : 2;
	c.len = a.len + b.len;
	c.v[0] = mul(a.v[x], b.v[y]); // miss both
	c.v[1] = mul(a.v[x], b.v[3]); // miss left
	c.v[2] = mul(a.v[3], b.v[y]); // miss right
	c.v[3] = mul(a.v[3], b.v[3]); // full
	if (ra != 1) return c;
	x = a.len == 1 ? 2 : 0;
	y = b.len == 1 ? 1 : 0;
	int val = 9 - lb;
	sadd(c.v[x ^ y], mul(a.v[0], b.v[0], val));
	sadd(c.v[x ^ 1], mul(a.v[0], b.v[1], val));
	sadd(c.v[2 ^ y], mul(a.v[2], b.v[0], val));
	sadd(c.v[2 ^ 1], mul(a.v[2], b.v[1], val));
	return c;
}

void build(int id = 1, int tl = 1, int tr = n) {
	st[id].len = tr - tl + 1;
	if (tl == tr) {
		st[id].v[0] = 1;
		st[id].v[3] = a[tl] + 1;
		return ;
	}
	build(left), build(right);
	st[id] = merge(st[id << 1], st[id << 1 | 1], a[tm], a[tm + 1]);
}

void upd(int p, int v, int id = 1, int tl = 1, int tr = n){
	if (tl == tr) {
		a[tl] = v;
		st[id].v[3] = v + 1;
		return ;
	}
	if (p > tm)
		upd(p, v, right);
	else
		upd(p, v, left);
	st[id] = merge(st[id << 1], st[id << 1 | 1], a[tm], a[tm + 1]);
}

#undef tm
#undef left
#undef right

void Hollwo_Pelw() {
	string s;
	cin >> n >> q >> s;
	for (int i = 1; i <= n; i++)
		a[i] = s[i - 1] - '0';
	build();
	for (int i = 1, p, x; i <= q; i++) {
		cin >> p >> x, upd(p, x);
		cout << st[1].v[3] << '\n';
	}
}