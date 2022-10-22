/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

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

const int N = 2e5 + 5;

int calc(int *a, int n) {
	int sx = 0, ex = 0, cx = 0;
	for (int i = 1; i <= n; i++) {
		cx += a[i];
		sx = min(sx, cx);
		ex = max(ex, cx);
	}
	return ex - sx + 1;
}

int p[N], pl[N], pr[N];
int s[N], sl[N], sr[N];

int solve(int *a, int n) {
	// a[i] = i - 1 -> i
	p[0] = s[n] = pl[0] = pr[0] = sl[n] = sr[n] = 0;
	for (int i = 1, v; i <= n; i++) {
		v = p[i] = p[i - 1] + a[i];
		pl[i] = min(pl[i - 1], v);
		pr[i] = max(pr[i - 1], v);
	}
	for (int i = n, v; i >= 1; i--) {
		v = s[i - 1] = s[i] + a[i];
		sl[i - 1] = min(sl[i], v);
		sr[i - 1] = max(sr[i], v);
	}

	int res = calc(a, n);
	for (int i = 0; i <= n; i++) {
		int lp = pl[i] - p[i], rp = pr[i] - p[i];
		int ls = s[i] - sr[i], rs = s[i] - sl[i];
		res = min(res, max(rp, rs + 1) - min(lp, ls + 1) + 1);
		res = min(res, max(rp + 1, rs) - min(lp + 1, ls) + 1);
	}
	return res;
}

int n, m, ud[N], lr[N];

void Hollwo_Pelw() {
	n = m = 0;
	string st; cin >> st;
	for (auto c : st) {
		if (c == 'W' || c == 'S') ud[++ n] = c == 'W' ? +1 : -1;
		if (c == 'D' || c == 'A') lr[++ m] = c == 'D' ? +1 : -1;
	}
	cout << min(1ll * solve(ud, n) * calc(lr, m),
				1ll * solve(lr, m) * calc(ud, n)) << '\n';
}