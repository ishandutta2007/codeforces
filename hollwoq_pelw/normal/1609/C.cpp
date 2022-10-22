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

const int N = 2e5 + 5, M = 1e6 + 5;

#define int long long

int pr[M];

struct __init__ {
	__init__() {
		fill(pr + 2, pr + M, 1);
		for (int i = 1; i < M; i++) if (pr[i])
			for (int j = i * 2; j < M; j += i) pr[j] = 0;
	}
} __init__;

int n, g, a[N];

inline int solve(const vector<int> &v) {
	int res = 0;
	for (int i = 0; i < v.size(); i++) if (pr[v[i]]) {
		int l = i, r = i;
		while (l > 0 && v[l - 1] == 1) l --;
		while (r + 1 < v.size() && v[r + 1] == 1) r ++;
		res += (i - l + 1) * (r - i + 1) - 1;
	}
	return res;
}

void Hollwo_Pelw() {
	cin >> n >> g;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	int res = 0;
	for (int x = 0; x < g; x++) {
		vector<int> tmp;

		for (int i = x; i < n; i += g) {
			if (a[i] > 1 && !pr[a[i]]) {
				res += solve(tmp);
				tmp.clear();
			} else {
				tmp.push_back(a[i]);
			}
		}

		if (tmp.size())
			res += solve(tmp);
	}

	cout << res << '\n';
}