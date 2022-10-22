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


const int N = 1e6 + 6;

int n, m, a[N], pref[N];
int bit[N], ans[N];
vector<pair<int, int>> qr[N];
map<int, int> lst;

inline void upd(int x, int v) {
	for (; x <= n; x += x & -x)
		bit[x] ^= v;
}

inline int query(int x) {
	int r = 0;
	for (; x; x -= x & -x)
		r ^= bit[x];
	return r;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], pref[i] = pref[i - 1] ^ a[i];
	cin >> m;
	for (int i = 1, l, r; i <= m; i++)
		cin >> l >> r, ans[i] = pref[r] ^ pref[l - 1], qr[r].emplace_back(l, i);
	for (int i = 1; i <= n; i++) {
		if (lst.count(a[i]))
			upd(lst[a[i]], a[i]);
		upd(lst[a[i]] = i, a[i]);
		for (auto li : qr[i])
			ans[li.second] ^= query(n) ^ query(li.first - 1);
	}
	for (int i = 1; i <= m; i++)
		cout << ans[i] << "\n";
}