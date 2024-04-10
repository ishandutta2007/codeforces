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
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 2e5 + 5;

int n, a[N], cnt[N], cur[N];

void Hollwo_Pelw() {
	cin >> n;
	fill(cur, cur + n + 1, 0);
	fill(cnt, cnt + n + 1, 0);
	for (int i = 1; i <= n; i++)
		cin >> a[i], cnt[a[i]] ++;
	
	int mx = 0;
	while (cnt[mx]) mx ++;

	vector<int> b;

	for (int i = 1, j = i; i <= n; i = j) {
		int c = - 1, nw = mx;
		while (j <= n && c < mx) {
			cur[a[j]] ++;
			cnt[a[j]] --;
			if (cnt[a[j]] == 0)
				nw = min(nw, a[j]);
			while (c < 0 || cur[c]) c ++;
			++ j;
		}
		for (int k = i; k < j; k++)
			cur[a[k]] = 0;
		b.push_back(mx); mx = nw;
	}

	cout << b.size() << '\n';
	for (auto v : b) cout << v << ' ';
	cout << '\n';
}