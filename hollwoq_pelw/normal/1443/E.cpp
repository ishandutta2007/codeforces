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
	FAST_IO("1443E.inp", "1443E.out");
#endif
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 2e5 + 5;

int n, q, a[N];
int64_t kth = 0, pref[N], fac[20];

void Hollwo_Pelw() {
	iota(a + 1, a + n + 1, 1);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		pref[i] = pref[i - 1] + i;

	fac[0] = 1;
	for (int i = 1; i <= 15; i++)
		fac[i] = fac[i - 1] * i;

	for (int t; q --; ) {
		cin >> t;
		if (t == 1) {
			int l, r; cin >> l >> r;
			cout << pref[r] - pref[l - 1] << '\n';
		} else {
			int x; cin >> x, kth += x;
			vector<int> per;
			for (int i = max(1, n - 14); i <= n; i++)
				per.push_back(i);
			{
				int64_t tmp = kth;
				for (int i = max(1, n - 14); i <= n; i++) {
					int p = 0;
					while (tmp >= fac[n - i])
						tmp -= fac[n - i], p ++;
					pref[i] = pref[i - 1] + per[p];
					per.erase(per.begin() + p);
				}
			}
		}
	}
}