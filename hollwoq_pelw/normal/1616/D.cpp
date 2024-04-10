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

const int N = 5e4 + 5;

#define int long long

int n, x, a[N], nxt[N];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cin >> x;

	vector<pair<int, int>> v;

	v.emplace_back(0, 0);

	for (int i = 1; i <= n; i++) {
		a[i] += a[i - 1] - x;
		v.emplace_back(a[i], i);
	}

	fill(nxt, nxt + n + 1, n + 1);

	sort(v.begin(), v.end());
	set<int> pos;

	for (int i = 0, j = 0; i <= n; i = j) {
		while (j <= n && v[i].first == v[j].first) j ++;

		for (int k = i; k < j; k++) {
			auto it = pos.upper_bound(v[k].second + 1);
			nxt[v[k].second] = it == pos.end() ? n + 1 : *it;
		}
		for (int k = i; k < j; k++)
			pos.insert(v[k].second);
	}

	int cur = n + 1, res = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (nxt[i] < cur) {
			cur = i + 1;
			res ++;
			// cout << i + 1 << "->";
		}
	}

	cout << n - res << '\n';
}