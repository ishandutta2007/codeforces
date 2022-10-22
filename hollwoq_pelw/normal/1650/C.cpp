#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen("hollwo_pelw.inp", "r")){
		freopen("hollwo_pelw.inp", "r", stdin);
		freopen("hollwo_pelw.out", "w", stdout);
	}
#else
	auto start = chrono::steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

#define int long long

const int N = 2e5 + 5;

int n, m, p[N], x[N], w[N];

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
		cin >> x[i] >> w[i];
	iota(p + 1, p + m + 1, 1);
	sort(p + 1, p + m + 1, [](const int &i, const int &j) {
		return w[i] < w[j]; 
	});
	sort(p + 1, p + 2 * n + 1, [](const int &i, const int &j){
		return x[i] < x[j];
	});
	int res = 0;
	for (int i = 1; i <= 2 * n; i++)
		res += w[p[i]];

	cout << res << '\n';
	for (int i = 1; i <= n; i++)
		cout << p[i] << ' ' << p[2 * n - i + 1] << '\n';
}