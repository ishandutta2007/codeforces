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

const int N = 1005;

int n, m, tr[N];
pair<int, int> dp[N], ok2[100], ok3[1000];
string s;

template<typename T>
inline bool chkmax(T &a, T b) {
	return a < b ? a = b, 1 : 0;
}

void Hollwo_Pelw() {
	cin >> n >> m;
	
	memset(ok2, 0, sizeof ok2);
	memset(ok3, 0, sizeof ok3);
	
	for (int i = 1; i <= n; i++) {
		cin >> s;
		for (int j = 1; j <= m; j++) {
			if (j >= 2)
				ok2[(s[j - 2] - '0') * 10 + s[j - 1] - '0'] = {i, j};
			if (j >= 3)
				ok3[(s[j - 3] - '0') * 100 + (s[j - 2] - '0') * 10 + s[j - 1] - '0'] = {i, j};
		}
	}

	cin >> s;
	fill(dp, dp + m + 1, pair<int, int>{0, 0});
	dp[0] = {1, 0};

	for (int i = 1; i <= m; i++) {

		if (i >= 2 && dp[i - 2].first)
			if (chkmax(dp[i], ok2[(s[i - 2] - '0') * 10 + s[i - 1] - '0'])) tr[i] = 2;

		if (i >= 3 && dp[i - 3].first)
			if (chkmax(dp[i], ok3[(s[i - 3] - '0') * 100 + (s[i - 2] - '0') * 10 + s[i - 1] - '0'])) tr[i] = 3;

	}

	if (!dp[m].first) {
		cout << "-1\n";
	} else {
		vector<tuple<int, int, int>> v;
		for (int p = m; p; ) {
			v.emplace_back(tr[p], dp[p].second, dp[p].first);
			p -= tr[p];
		}
		reverse(v.begin(), v.end());
		cout << v.size() << '\n';
		for (auto [l, r, i] : v)
			cout << r - l + 1 << ' ' << r << ' ' << i << '\n';
	}
}