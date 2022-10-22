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

const int N = 2e5 + 2999, SZ = 450;

int n, k, q, a[N], b[N], c[N], cntzer;

int val[N], npos[N], lstpos[N];

int cnt[SZ][1 << 14], lz[SZ];

inline void upd_single(int i, int x) {
	-- cnt[i / SZ][val[i]];
	val[i] ^= x;
	++ cnt[i / SZ][val[i]];
}

void __upd__(int p, int x) {
	int l = npos[p], r = lstpos[p % k], lb = l / SZ, rb = r / SZ;

	cntzer -= val[r] == lz[rb];

	if (lb == rb) {
		for (int i = l; i <= r; i++)
			upd_single(i, x);
	} else {
		for (int i = l; i < (lb + 1) * SZ; i++)
			upd_single(i, x);
		for (int i = rb * SZ; i <= r; i++)
			upd_single(i, x);
		for (int j = lb + 1; j < rb; j++) lz[j] ^= x;
	}

	cntzer += val[r] == lz[rb];
}

void __do_query__() {
	if (cntzer != k)
		return cout << "-1\n", (void) 0;
	int ans = n + 1;
	for (int i = 0; i < SZ; i++)
		ans -= cnt[i][lz[i]];
	cout << ans << '\n';
}

void __build__() {
	for (int i = 0, sz = 0; i < k; i++) {
		for (int j = i; j <= n; j += k) {
			val[sz] = c[j] ^ (j == i ? 0 : val[sz - 1]);
			npos[j] = sz ++;
		}
		lstpos[i] = sz - 1;
		cntzer += val[sz - 1] == 0;
	}
	for (int i = 0; i <= n; i++)
		cnt[i / SZ][val[i]] ++;
	__do_query__();
}

void Hollwo_Pelw() {
	cin >> n >> k >> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) c[i] = a[i] ^ b[i];
	for (int i = n; i > 0; i--) c[i] ^= c[i - 1];
	// c[i] -> c[i + k] -> c[i + 2k] ... => sum xor == 0; => ways can save = number of zeros ?
	__build__();
	for (int _ = 0, p, x, v; _ < q; _++) {
		char t; cin >> t >> p >> x, --p;
		if (t == 'a')
			v = a[p] ^ x, a[p] = x;
		else
			v = b[p] ^ x, b[p] = x;
		__upd__(p, v), __upd__(p + 1, v), __do_query__();
	}
}