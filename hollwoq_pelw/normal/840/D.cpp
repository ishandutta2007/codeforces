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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 3e5 + 5;

struct query {
	int l, r, k, id;
	bool operator < (const query &oth) const {
		if ((l >> 9) != (oth.l >> 9))
			return l < oth.l;
		return (l >> 9) & 1 ? r > oth.r : r < oth.r;
	}
} qr[N];

int n, q, res[N], a[N], cnt[N], l = 0, r = -1;

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0, l, r, k; i < q; i++)
		cin >> l >> r >> k, qr[i] = {l - 1, r - 1, (r - l + 1) / k, i};
	sort(qr, qr + q);
	for (int i = 0; i < q; i++) {
		while (l > qr[i].l) cnt[a[-- l]] ++;
		while (r < qr[i].r) cnt[a[++ r]] ++;
		while (l < qr[i].l) cnt[a[l ++]] --;
		while (r > qr[i].r) cnt[a[r --]] --;
		int ans = -1;
		for (int _ = 0, v; _ < 75; _++) {
			v = a[rng() % (r - l + 1) + l];
			if (cnt[v] > qr[i].k)
				ans = ans == -1 || ans > v ? v : ans;
		}
		res[qr[i].id] = ans;
	}
	for (int i = 0; i < q; i++)
		cout << res[i] << '\n';
}