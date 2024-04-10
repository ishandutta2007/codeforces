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

const int N = 1e5 + 5;

int n, a[N];
long long b[N], k;

long long f(int i, long long x) {
	return -3ll * x * x + 3ll * x + a[i] - 1;
}

long long solve(long long mx) {
	long long tot = 0;
	for (int i = 1; i <= n; i++) {
		int l = 0, r = a[i]; b[i] = 0;
		while (l <= r) {
			int m = l + r >> 1;
			if (f(i, m) >= mx)
				l = m + 1, b[i] = m;
			else
				r = m - 1;
		}
		tot += b[i];
	}
	return tot;
}

void Hollwo_Pelw() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	long long l = -4e18, r = 4e18, res = 0;
	while (l <= r) {
		long long m = (l + r) / 2;
		if (solve(m) >= k)
			res = m, l = m + 1;
		else
			r = m - 1;
	}
	k -= solve(res);

	for (int i = 1; i <= n; i++)
		while (k < 0 && f(i, b[i]) == res)
			k ++, b[i] --;
	for (int i = 1; i <= n; i++)
		cout << b[i] << ' ';
}