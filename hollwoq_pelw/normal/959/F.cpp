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

const int N = 1e5 + 5, mod = 1e9 + 7;

int n, q, a[N], res[N], pw[N], basis[20], sz;
vector<pair<int, int>> qr[N];

bool insert_basis(int mask, bool tp = 0) {
	for (int i = 0; i < 20; i++) if (mask >> i & 1) {
		if (!basis[i])
			return basis[i] = tp ? 0 : mask, 1;
		mask ^= basis[i];
	}
	return 0;
}

void Hollwo_Pelw() {
	cin >> n >> q;
	pw[0] = 1;
	for (int i = 1; i <= n; i++)
		cin >> a[i], pw[i] = 2ll * pw[i - 1] % mod;
	for (int i = 1, p, x; i <= q; i++)
		cin >> p >> x, qr[p].emplace_back(x, i);
	
	for (int i = 1; i <= n; i++) {
		sz += insert_basis(a[i]);
		for (auto vp : qr[i])
			res[vp.second] = insert_basis(vp.first, 1) ? 0 : pw[i - sz];
	}

	for (int i = 1; i <= q; i++)
		cout << res[i] << '\n';
}