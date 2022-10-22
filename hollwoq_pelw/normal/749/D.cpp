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

const int N = 2e5 + 5;

int n, q, a[N], b[N], blk[N], idx[N];
vector<int> v[N];

void Hollwo_Pelw() {
	cin >> n, v[0] = {0};
	for (int i = 1, x, y; i <= n; i++)
		cin >> x >> y, a[x] = y, v[x].push_back(y);
	iota(idx, idx + n + 1, 0);
	sort(idx + 1, idx + n + 1, [](const int &x, const int &y){
		return a[x] > a[y];
	});
	cin >> q;
	for (int _ = 0, k, i; _ < q; _++) {
		for (cin >> k, i = 0; i < k; i++)
			cin >> b[i], blk[b[i]] = 1;

		int f = 0, s = 0;
		for (i = 1; i <= n; i++) {
			int id = idx[i];
			if (!a[id]) break ;
			if (blk[id]) continue ;
			(f ? s = id : f = id);
			if (s) break ;
		}

		int p = lower_bound(v[f].begin(), v[f].end(), a[s]) - v[f].begin();
		cout << f << ' ' << v[f][p] << '\n';

		for (i = 0; i < k; i++) blk[b[i]] = 0;
	}
}