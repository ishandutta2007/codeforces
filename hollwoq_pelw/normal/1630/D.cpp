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
	cin >> testcases;
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

#define int long long

const int N = 1e6 + 5;

int n, m, a[N], sg[N];
vector<int> v[N];

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int g = 0, tot = 0;
	for (int i = 1, b; i <= m; i++)
		cin >> b, g = __gcd(g, b);

	for (int i = 0; i < g; i++)
		v[i].clear(), sg[i] = 1;
	
	for (int i = 0; i < n; i++) {
		tot += abs(a[i]);
		v[i % g].push_back(abs(a[i]));
		if (a[i] < 0)
			sg[i % g] *= -1;
	}

	int c0 = 0, c1 = 0;

	for (int i = 0; i < g; i++) {
		if (sg[i] < 0) {
			c0 += *min_element(v[i].begin(), v[i].end());
		} else {
			c1 += *min_element(v[i].begin(), v[i].end());
		}
	}

	cout << tot - min(c0, c1) * 2 << '\n';
}