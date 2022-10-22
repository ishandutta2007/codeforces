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

const int N = 3005;

int n, k, d[N][N], res, p[N];

queue<pair<int, int>> q;

int cankill[N], cansurv[N];

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	cansurv[n + 1] = 1;
	cankill[n + 1] = 0;

	for (int i = n; i; i--) {
		cansurv[i] = cansurv[i + 1] && (p[i] != 100);
		cankill[i] = cankill[i + 1] || (p[i] !=   0);
	}

	memset(d, -1, sizeof d);

	q.emplace(1, 2);
	d[1][2] = 0;

	while (!q.empty()) {
		auto [f, s] = q.front(); q.pop();

		if (d[f][s] > k) continue ;

		++ res;
		// cout << f << ' ' << s << ' ' << d[f][s] << '\n';

		if (s > n) continue ;

		// f, s + 1
		if (cansurv[s] && p[f] !=   0)
			if (d[f][s + 1] == -1)
				d[f][s + 1] = d[f][s] + 1, q.emplace(f, s + 1);
		// s, s + 1
		if (cankill[s] && p[f] != 100)
			if (d[s][s + 1] == -1)
				d[s][s + 1] = d[f][s] + 1, q.emplace(s, s + 1);
		// s + 1, s + 2
		if (cankill[s] && p[f] !=   0)
			if (d[s + 1][s + 2] == -1)
				d[s + 1][s + 2] = d[f][s] + 1, q.emplace(s + 1, s + 2);
	}

	cout << res << '\n';
}