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


const int N = 15, M = 1e4 + 5;

int n, m, a[N], delta[M], p[M], res[M];
vector<int> vec[N * 2];

long long ans;
string s[N];

void Hollwo_Pelw() {
	cin >> n >> m;

	ans = -1;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> s[i];

	for (int mask = 0; mask < 1 << n; mask++) {
		fill(delta, delta + m, 0);
		long long cur = 0;
		for (int i = 0; i < n; i++) {
			int f = mask >> i & 1 ? 1 : -1;
			cur -= f * a[i];

			for (int j = 0; j < m; j++) 
				if (s[i][j] == '1') delta[j] += f;
		}

		for (int i = 0; i < m; i++)
			vec[delta[i] + N].push_back(i);

		for (int i = 0, f = 1; i < N * 2; i++) {
			for (auto v : vec[i]) {
				cur += f * delta[v];
				p[v] = f ++;
			}
			vec[i].clear();
		}

		if (cur > ans) {
			ans = cur;
			for (int i = 0; i < m; i++)
				res[i] = p[i];
		}
	}

	for (int i = 0; i < m; i++)
		cout << res[i] << ' ';
	cout << '\n';
}