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
const int N = 303, mod = 1e9 + 7;

int n, cnt, sz[N], a[N], g[N], pre[N], dp[N][N];

int inv[N], fac[N];

struct __initial__ {
	__initial__ () {
		inv[0] = inv[1] = fac[0] = fac[1] = 1;
		for (int i = 2; i < N; i++)
			inv[i] = mod - (mod / i) * inv[mod % i] % mod;
		for (int i = 2; i < N; i++)
			fac[i] = fac[i - 1] * i % mod, inv[i] = inv[i - 1] * inv[i] % mod;
	}
} __init__;

int C(int n, int k) {
	if (k > n || k < 0) return 0;
	return fac[n] * inv[k] % mod * inv[n - k] % mod;
}

bool isq(int x) {
	return (int) sqrt(x) * (int) sqrt(x) == x;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		for (int j = 1; j < i; j++)
			if (isq(a[i] * a[j]))
				g[i] = g[j];
		if (!g[i]) g[i] = ++ cnt;
		sz[g[i]] ++;
	}
	for (int i = 1; i <= cnt; i++)
		pre[i] = pre[i - 1] + sz[i];
	dp[1][sz[1] - 1] = fac[sz[1]];
	for (int i = 2; i <= cnt; i++) {
		for (int j = 0; j < pre[i - 1]; j++) {
			for (int k = 1; k <= sz[i]; k++) {
				for (int l = 0; l <= min(j, k); l++) {
					int tmp = C(sz[i] - 1, k - 1) * C(j, l) % mod * C(pre[i - 1] - j + 1, k - l) % mod;
					dp[i][sz[i] + j - k - l] = (dp[i][sz[i] + j - k - l] + dp[i - 1][j] * tmp % mod) % mod;
				}
			}
		}
		for (int j = 0; j < pre[i]; j++)
			dp[i][j] = dp[i][j] * fac[sz[i]] % mod;
	}
	cout << dp[cnt][0];
}