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

const int N = 2e5 + 5;

#define int long long
int n, q, a[N], b[N], mu[N], v[N], st[N], sz, res, pre[N];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	b[1] = a[1];

	{
		mu[1] = 1;
		for (int i = 1; i <= n; i++) {
			v[i] = b[i] - a[i];
			for (int j = 2 * i; j <= n; j += i)
				mu[j] -= mu[i], a[j] += v[i];
			a[i] = b[i];
		}
	}

	for (int i = 1; i <= n; i++) {
		if (mu[i])
			st[++ sz] = (mu[i] * v[i]);
		else 
			res += abs(v[i]);
	}

	sort(st + 1, st + sz + 1);

	for (int i = 1; i <= sz; i++)
		pre[i] = pre[i - 1] + st[i];

	cin >> q;
	for (int x; q --; ) {
		cin >> x, x -= a[1];
		int p = upper_bound(st + 1, st + sz + 1, - x) - st - 1;
		cout << res + pre[sz] - pre[p] + (sz - p) * x
					- (pre[p] + p * x) << '\n';
	}
}