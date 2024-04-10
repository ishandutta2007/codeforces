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
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 1e4 + 5, M = 1e2 + 5, inf = 1e9 + 7;

int dpmin[N][M], dpmax[N][M], p, m, n;
string s;

inline void smax(int &a, int b) { a = a > b ? a : b; }
inline void smin(int &a, int b) { a = a < b ? a : b; }

void Hollwo_Pelw() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			dpmin[i][j] = inf, dpmax[i][j] = -inf;

	cin >> s >> p >> m;

	vector<int> st;
	for (char c : s) {
		if ('0' <= c && c <= '9') {
			st.push_back(++ n);
			dpmin[n][0] = dpmax[n][0] = c - '0';
		}
		if (c == ')') {
			int r = st.back(); st.pop_back();
			int l = st.back(); st.pop_back();
			st.push_back(++ n);
			if (p > m) {
				for (int i = 0; i <= m; i++) for (int j = 0; i + j <= m; j++) {
					smax(dpmax[n][i + j], dpmax[l][i] + dpmax[r][j]);
					smin(dpmin[n][i + j], dpmin[l][i] + dpmin[r][j]);
					smax(dpmax[n][i + j + 1], dpmax[l][i] - dpmin[r][j]);
					smin(dpmin[n][i + j + 1], dpmin[l][i] - dpmax[r][j]);
				}
			} else {
				for (int i = 0; i <= p; i++) for (int j = 0; i + j <= p; j++) {
					smax(dpmax[n][i + j + 1], dpmax[l][i] + dpmax[r][j]);
					smin(dpmin[n][i + j + 1], dpmin[l][i] + dpmin[r][j]);
					smax(dpmax[n][i + j], dpmax[l][i] - dpmin[r][j]);
					smin(dpmin[n][i + j], dpmin[l][i] - dpmax[r][j]);
				}
			}
		}
	}
	cout << dpmax[n][min(p, m)] << '\n';
}