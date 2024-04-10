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

#define int long long
const int N = 2e5 + 5;

int n, s[N], p[N], bit[N];

inline void add(int x, int v) {
	for (; x <= n; x += x & -x)
		bit[x] += v;
}

inline int query(int x) {
	int p = 0;
	for (int i = 18; i >= 0; i--) {
		p += 1 << i;
		if (p > n || bit[p] >= x)
			p -= 1 << i;
		else
			x -= bit[p];
	}
	return p + 1;
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> s[i], add(i, i);
	for (int i = n; i >= 1; i--) {
		p[i] = query(s[i] + 1);
		add(p[i], - p[i]);
	}
	for (int i = 1; i <= n; i++)
		cout << p[i] << ' ';

}