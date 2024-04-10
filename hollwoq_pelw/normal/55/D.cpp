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
    cin >> testcases;
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

long long dp[20][50][2520];

int comp[2600], nlcm[2600][10], nmod[2600][10], dig[20];

struct __initial__ {
	__initial__ () {
		memset(dp, -1, sizeof dp);
		for (int i = 1, cnt = 0; i <= 2520; i++)
			if (2520 % i == 0) comp[i] = ++cnt;
		for (int i = 0; i <= 2520; i++) for (int j = 0; j < 10; j++)
			nlcm[i][j] = j ? i / __gcd(i, j) * j : i, nmod[i][j] = (i * 10 + j) % 2520;
	}
} __init__;

long long calc(int d, int lcm, int mod, bool f) {
	int p = comp[lcm], l = (f ? 9 : dig[d]);
	long long res = 0;
	if (d == 0) return mod % lcm == 0;
	if (f && dp[d][p][mod] != -1) return dp[d][p][mod];
	for (int i = 0; i <= l; i++)
		res += calc(d - 1, nlcm[lcm][i], nmod[mod][i], f | (i < l));
	if (f) return dp[d][p][mod] = res;
	return res;
}

long long solve(long long x){
	int p = 0; while (x)
		dig[++ p] = x % 10, x /= 10;
	return calc(p, 1, 0, 0);
}

void Hollwo_Pelw() {
	long long l, r; cin >> l >> r;
	cout << solve(r) - solve(l - 1) << '\n';
}