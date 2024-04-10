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
	FAST_IO("1593F.inp", "1593F.out");
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

const int N = 45;

int dp[N][N][N][N << 1], n, a, b;
pair<int, int> tr[N][N][N][N << 1];
char s[N];
 
void Hollwo_Pelw() {
	cin >> n >> a >> b >> s;
	memset(dp, -1, sizeof dp);
 
	// a -> red
	// b -> black
	dp[0][0][0][N] = 0;
	for (int i = 0; i < n; i++) {
		for (int ra = 0; ra < a; ra++) {
			for (int rb = 0; rb < b; rb++) {
				for (int j = 0; j < 90; j++) {
					if (dp[i][ra][rb][j] == -1) continue ;
 
					if (j < 89 && dp[i + 1][(ra * 10 + s[i] - '0') % a][rb][j + 1] == -1) {
						dp[i + 1][(ra * 10 + s[i] - '0') % a][rb][j + 1] = 1;
						tr[i + 1][(ra * 10 + s[i] - '0') % a][rb][j + 1] = {ra, rb};
					}
 
					if (j > 0 && dp[i + 1][ra][(rb * 10 + s[i] - '0') % b][j - 1] == -1) {
						dp[i + 1][ra][(rb * 10 + s[i] - '0') % b][j - 1] = 0;
						tr[i + 1][ra][(rb * 10 + s[i] - '0') % b][j - 1] = {ra, rb};
					}
					// cout << i << ' ' << ra << ' ' << rb << ' ' << oka << ' ' << okb << '\n';
				}
			}
		}
	}
 
	int best = 0;
 
	for (int i = 0; i < 90; i++)
		if (dp[n][0][0][i] != -1)
			if (abs(best - N) > abs(i - N)) best = i;
 
	if (abs(best - N) >= n) {
		cout << "-1\n";
		return ;
	}
 
	string res = "";
	
	for (int i = n, ra = 0, rb = 0; i; i --) {
		auto [na, nb] = tr[i][ra][rb][best];
		int v = dp[i][ra][rb][best];
		res += "BR"[v], ra = na, rb = nb;
		best = (v ? best - 1 : best + 1);
	}
 
	reverse(res.begin(), res.end());
	cout << res << '\n';
}