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

#define int long long
const int N = 1e5 + 5, inf = 2e9;

int n, a[N], b[N], pa[N], pb[N];

bool solve(int x) {
	int val = x - x / 4, ex = x - n;
	int sa = val <= ex ? val * 100 : pa[val - ex] + ex * 100;
	int sb = pb[min(n, val)];
	return sa >= sb;
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	sort(a + 1, a + n + 1, greater<int>());
	sort(b + 1, b + n + 1, greater<int>());
	for (int i = 1; i <= n; i++) pa[i] = pa[i - 1] + a[i];
	for (int i = 1; i <= n; i++) pb[i] = pb[i - 1] + b[i];
	int l = n, r = 1e9, res = 1e9;
	while (l <= r) {
		int m = l + r + 1 >> 1;
		if (solve(m))
			res = m, r = m - 1;
		else
			l = m + 1;
	}
	cout << res - n << '\n';
}