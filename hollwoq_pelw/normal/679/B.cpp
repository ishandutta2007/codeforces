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
	FAST_IO("679B.inp", "679B.out");
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

const int N = 5e5 + 5;

#define int int64_t

int64_t best[N];
int a[N];

inline int64_t cube(int x) {
	return x * x * x;
}

pair<int, int64_t> solve(int64_t m) {
	if (m < N) return {a[best[m]], best[m]};
	int t = cbrt(m);
	auto tmp1 = solve(m - cube(t)), tmp2 = solve(cube(t) - 1 - cube(t - 1));
	return max(
		pair<int, int>(tmp1.first + 1, tmp1.second + cube(t)),
		pair<int, int>(tmp2.first + 1, tmp2.second + cube(t - 1))
	);
}

void Hollwo_Pelw() {
	for (int i = 1; i < N; i++) {
		int t = cbrt(i);
		a[i] = a[i - t * t * t] + 1;
	}
	for (int i = 1; i < N; i++) {
		best[i] = best[i - 1];
		if (a[i] >= a[best[i]])
			best[i] = i;
	}

	int64_t m; cin >> m; auto ans = solve(m);
	cout << ans.first << ' ' << ans.second << '\n';
}