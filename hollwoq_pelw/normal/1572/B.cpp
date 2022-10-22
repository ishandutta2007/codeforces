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

int n, a[N], tot;
vector<int> opt;

inline void do_opt(int p){
	int x = a[p] ^ a[p + 1] ^ a[p + 2]; 
	opt.push_back(p), a[p] = a[p + 1] = a[p + 2] = x;
}

void Hollwo_Pelw() {
	cin >> n, tot = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i], tot ^= a[i];
	if (tot) return cout << "NO\n", (void) 0;
	int pos = 0;
	for (int i = 1; i <= n && !pos; i++)
		if ((tot ^= a[i]) == 0 && (i & 1)) pos = i; 
	if (!pos) return cout << "NO\n", (void) 0;
	
	opt.clear();

	for (int p = pos - 2; p >= 1; p -= 2) do_opt(p);
	for (int p = pos + 1; p <= n - 2; p += 2) do_opt(p);
	for (int p = 1; p <= n - 2; p += 2) do_opt(p);
	for (int i = 1; i <= n; i++) assert(a[i] == 0);

	cout << "YES\n" << opt.size() << '\n';
	for (auto v : opt) cout << v << ' '; cout << '\n';
}