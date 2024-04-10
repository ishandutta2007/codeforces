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
	FAST_IO(".inp", ".out");
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

#define int long long

const int N = 5e5 + 5, inf = 1e18;

int n, m, a[N], p[N], b[N], ind[N], bit[N];

inline void upd(int x, int v) {
	// cout << "update " << x << ' ' << v << endl;
	for (++ x; x < N; x += x & -x)
		bit[x] += v;
}

inline int query(int x) {
	// cout << "query " << x + 1 << " = ";
	int r = 0;
	for (++ x; x; x -= x & -x)
		r += bit[x];
	// cout << r << "\n";
	return r;
}

inline void add_val(int i) {
	upd(0, p[i]); 
	if (p[i] > 0) {
		int x = lower_bound(b + 1, b + m + 1, a[i]) - b;
		upd(x, - p[i]);
	}
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> p[i];
	cin >> m;
	for (int i = 1; i <= m; i++) 
		cin >> b[i], ind[b[i]] = i;
	upd(1, inf);
	for (int i = 1; i <= n; i++) {
		// cout << ">>>>>>> " << "solve " << i << " <<<<<<<\n";
		if (ind[a[i]]) {
			int lst = query(ind[a[i]] - 1);
			add_val(i);
			int cur = query(ind[a[i]]);
			if (lst < cur) {
				upd(ind[a[i]], lst - cur), upd(ind[a[i]] + 1, cur - lst);
			}
		} else {
			add_val(i);
		}
	}
	int res = query(m);
	if (res > (int) 1e15)
		return cout << "NO\n", (void) 0;
	cout << "YES\n" << res;
}