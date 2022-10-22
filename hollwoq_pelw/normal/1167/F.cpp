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

const int N = 5e5 + 5, mod = 1e9 + 7;

int n, a[N], b[N];
long long bit[N];

void add(int p, int v) {
	for (; p <= n; p += p & -p)
		bit[p] += v;
}

long long query(int p) {
	long long r = 0;
	for (; p; p -= p & -p)
		r += bit[p];
	return r;
}

int cnt[2][N];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i], b[i] = a[i];
	sort(b + 1, b + n + 1);
	for (int id = 0; id < 2; id++) {

		fill(bit + 1, bit + n + 1, 0);

		for (int i = 1, p; i <= n; i++) {
			p = lower_bound(b + 1, b + n + 1, a[i]) - b;
			cnt[id][i] = query(p) % mod, add(p, i);
		}

		reverse(a + 1, a + n + 1);
	}

	reverse(cnt[1] + 1, cnt[1] + n + 1);
	
	long long ans = 0;
	for (int i = 1, j = n; i <= n; i++, j--) {
		ans += (1ll * cnt[0][i] * j + 1ll * cnt[1][i] * i + 1ll * i * j) % mod * a[i] % mod;
	}
	cout << ans % mod;
}