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
	// cin >> testcases;
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
 
const int N = 1e6 + 5;
 
int n, m, q, p[N];
 
void Hollwo_Pelw(){

	cin >> n >> m;
	for (int i = 1, c, d, h; i <= n; i++) {
		cin >> c >> d >> h;
		p[c] = max(p[c], d * h);
	}
	for (int i = 1; i <= m; i++)
		for (int j = 2 * i; j <= m; j += i)
			p[j] = max(p[j], p[i] * (j / i));	
 
	for (int i = 1; i <= m; i++)
		p[i] = max(p[i], p[i - 1]);
 
	// for (int i = 1; i <= m; i++)
	// 	cout << p[i] << " \n"[i == m];
 
	cin >> q;
 
	for (int d, h; q --; ) {
		cin >> d >> h;
		int r = upper_bound(p + 1, p + m + 1, d * h) - p;
		if (r > m)
			cout << "-1 ";
		else
			cout << r << ' ';
	}

}