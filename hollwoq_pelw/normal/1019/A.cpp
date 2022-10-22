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
	FAST_IO("election.inp", "election.out");
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

const int N = 3e3 + 5;

int n, a[N], b[N], cnt;
bool used[N];

vector<int> occ, allp, val[N];

inline int64_t solve(int f) {
	fill(used + 1, used + n + 1, 0);
	int64_t res = 0;

	int need = f - cnt, p = 0;

	for (auto v : occ) {
		if (val[v].size() >= f) {
			for (int i = 0; i <= val[v].size() - f; i++) {
				res += b[val[v][i]], used[val[v][i]] = 1, -- need;
			}
		}
	}

	while (need > 0 && p < allp.size()) {
		if (!used[allp[p]])
			-- need, res += b[allp[p]];
		++ p;
	}

	return res;
}

void Hollwo_Pelw() {
	cin >> n >> cnt, cnt = n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		if (-- a[i]) {
			val[a[i]].push_back(i);
			allp.push_back(i), cnt --;
		}
	}
	
	for (int i = 1; i < N; i++) if (val[i].size()) {
		occ.push_back(i);
		sort(val[i].begin(), val[i].end(), [](const int &x, const int &y) {
			return b[x] < b[y];
		});
	}

	sort(allp.begin(), allp.end(), [](const int &x, const int &y) {
		return b[x] < b[y];
	});

	int l = cnt, r = n;
	while (l < r) {
		int m = l + r >> 1;
		if (solve(m + 1) > solve(m))
			r = m;
		else
			l = m + 1;
	}

	cout << solve(l) << '\n';
}