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

const int N = 2e5 + 5;
 
#define int long long
 
int n, k, a[N];
 
void Hollwo_Pelw() {
	cin >> n >> k;
 
	int res = 1e18, tot = 0;
 
	for (int i = 0; i < n; i++)
		cin >> a[i], tot += a[i];
 
	if (tot <= k) {
		cout << 0 << '\n';
		return ;
	}
 
	sort(a, a + n);
 
	tot -= a[0];
 
	for (int set = 1; set <= n; set++) {
		// a[0] * set + tot <= k
		int cur = k - tot;
		int val = cur / set;
 
		while (val * set > cur)
			val --;
 
		res = min(res, max(a[0] - val, 0ll) + set - 1);
 
		tot -= a[n - set];
	}
 
	cout << res << '\n';
}