/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

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

#define int long long

const int N = 20;

int n, k, cnt;

double p[N], dp[1 << N], res[N];

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) 
		cin >> p[i], cnt += p[i] > 1e-6;
	dp[0] = 1, k = min(k, cnt);
	for (int mask = 0; mask < (1 << n); mask++) {
		double tot = 0; // tot = 1 ? :)))) => runtime
		for (int i = 0; i < n; i++)
			if (mask >> i & 1) tot += p[i];
		for (int i = 0; i < n; i++)
			if (!(mask >> i & 1)) dp[mask | 1 << i] += dp[mask] * p[i] / (1 - tot);		
		if (__builtin_popcount(mask) == k)
			for (int i = 0; i < n; i++)
				if (mask >> i & 1)
					res[i] += dp[mask];
	}
	for (int i = 0; i < n; i++)
		cout << fixed << setprecision(6) << res[i] << ' ';
}