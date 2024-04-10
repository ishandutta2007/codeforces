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

const int N = 5e5 + 5;

int n, bit[N], p[N], ans;
array<int, 3> a[N];


#define max __max__ 

inline int max(int a, int b) { return a > b ? a : b; }
inline void smax(int &a, int b) { a = a > b ? a : b; }

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i][0];
	for (int i = 1; i <= n; i++) cin >> a[i][1], p[i] = a[i][1];
	for (int i = 1; i <= n; i++) cin >> a[i][2];
	sort(a + 1, a + n + 1);
	sort(p + 1, p + n + 1);
	for (int i = 1; i <= n; i++)
		a[i][1] = lower_bound(p + 1, p + n + 1, a[i][1]) - p;
	
	for (int i = n, j = n; i; i = j - 1) {
		while (j > 1 && a[j - 1][0] == a[i][0]) j--;
		for (int k = j; k <= i; k++) {
			int res = 0;
			for (int x = n - a[k][1]; x; x -= x & -x)
				smax(res, bit[x]);
			ans += res > a[k][2];
		}
		for (int k = j; k <= i; k++) {
			for (int x = n - a[k][1] + 1; x <= n; x += x & -x)
				smax(bit[x], a[k][2]);
		}
	}
	cout << ans;
}