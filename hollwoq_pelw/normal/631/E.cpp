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

const int N = 2e5 + 5, mod = 1e9 + 7;

int n, a[N];
long long pre[N], res, ans;

inline bool smax(long long &a, long long b) {
	return a < b ? a = b, 1 : 0;
}

inline long long calc(int i, int j) {
	return i <= j ? 1ll * a[i] * (j - i) - pre[j] + pre[i] : 
				pre[i - 1] - pre[j - 1] - 1ll * a[i] * (i - j);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], pre[i] = pre[i - 1] + a[i], res += 1ll * a[i] * i;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = n;
		while (r - l >= 3) {
			int ml = l + (r - l) / 3, mr = r - (r - l) / 3;
			(calc(i, ml) > calc(i, mr) ?  r = mr : l = ml);
		}
		for (int j = l; j <= r; j++)
			smax(ans, calc(i, j));
	}
	cout << ans + res;
}