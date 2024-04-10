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
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 2e5 + 5, B = 100;

int n, a[N], cnt[N], mxfreq, res = 0;
int last[2 * N], curcnt[N];


inline void solve_big(int oth) {
	fill(last, last + 2 * n + 1, -1);
	last[n] = 0;
	for (int i = 1, cur = n; i <= n; i++) {
		cur += (a[i] == mxfreq) - (a[i] == oth);
		if (~last[cur])
			res = max(res, i - last[cur]);
		else
			last[cur] = i;
	} 
}

inline void solve_small(int mx) {
	fill(curcnt + 1, curcnt + n + 1, 0);
	int mxcnt = 0;
	for (int l = 1, r = 1; r <= n; ++ r) {
		mxcnt += (++ curcnt[a[r]]) == mx;
		for (; l <= r && curcnt[a[r]] > mx; l ++)
			mxcnt -= (curcnt[a[l]] --) == mx;
		if (mxcnt >= 2)
			res = max(res, r - l + 1);
	}
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if ((++ cnt[a[i]]) > cnt[mxfreq])
			mxfreq = a[i];
	}

	for (int i = 1; i <= n; i++)
		if (i != mxfreq && cnt[mxfreq] == cnt[i])
			return cout << n << '\n', (void) 0;

	for (int i = 1; i <= n; i++)
		if (i != mxfreq && cnt[i] > B)
			solve_big(i);

	for (int i = 1; i <= B; i++)
		solve_small(i);
	cout << res << '\n';
}