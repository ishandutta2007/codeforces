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
const int N = 2e5 + 5;

int n, bit[N], ans;

vector<int> p[N];

inline void add(int x, int v) {
	for (; x < N; x += x & -x)
		bit[x] += v;
}

inline void query(int x) {
	for (; x; x -= x & -x)
		ans += bit[x];
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, a; i <= n; i++) {
		cin >> a, a = min(a, n);
		query(a);
		if (a > i)
			add(i, 1), p[a].push_back(i);
		for (auto j : p[i])
			add(j, -1);
	}
	cout << ans;
}