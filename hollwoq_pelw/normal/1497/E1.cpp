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
	FAST_IO(".inp", ".out");
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

const int N = 2e5 + 5, M = 1e7 + 5;

int n, k, a[N], p[M], prv[M], dp[22], lst[22];

struct __initial__ {
	__initial__ () {
		for (int i = 1; i < M; i++) p[i] = i;
		for (int i = 2; i < M / i + 5; i++) {
			for (int j = i * i, v = i * i; j < M; j += v)
				while (p[j] % v == 0) p[j] /= v;
		}
	}
} __init__;

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i], prv[a[i] = p[a[i]]] = -1;
	memset(dp, 0, sizeof dp), memset(lst, 0, sizeof lst);
	for (int i = 1, p; i <= n; i++) {
		p = prv[a[i]], prv[a[i]] = i;
		for (int j = k; j >= 0; j--) if (lst[j] <= p) {
			if (j < k && (dp[j + 1] > dp[j] || dp[j + 1] == dp[j] && lst[j + 1] < lst[j]))
				dp[j + 1] = dp[j], lst[j + 1] = lst[j];
			dp[j] ++, lst[j] = i;
		}
	}
	cout << dp[k] + 1 << '\n';
}