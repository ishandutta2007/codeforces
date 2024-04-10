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

const int N = 1 << 11;

int d, n, a[N], bet[N], vis[N], match[N];
vector<int> g[N];

bool dfs(int v) {
	if (vis[v]) return 0;
 
	vis[v] = 1;
	for(int s : g[v]) {
		if (match[s] == -1 || dfs(match[s])) {
			match[s] = v;
			match[v] = s;
			return 1;
		}
	}
	return 0;
}

void Hollwo_Pelw() {
	cin >> d >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < d; j++)
			a[i] |= (s[j] == '1') << j;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (i != j) {
			if (a[i] == (a[i] & a[j]))
				g[i].push_back(j + n);
		}
	
	memset(match, -1, sizeof match);

	vector<int> p(n);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [](const int &x, const int &y){
		return __builtin_popcount(a[x]) > __builtin_popcount(a[y]);
	});

	int r_use = n - 1;
	for (int i = 0; i < n; i++) {
		memset(vis, 0, sizeof vis);
		r_use -= dfs(p[i]);
	}

	for (int i = 0; i < n; i++)
		if (~match[i]) bet[match[i] - n] = 1;

	string res = "";

	memset(vis, 0, sizeof vis);
	for (int i = 0; i < n; i++) if (!bet[i]) {
		int u = i, cur = 0; vis[u] = 1;
		if (!res.empty()) res += 'R';

		vector<int> path(1, u);
		while (1) {
			if (!~match[u]) break ;
			u = match[u] - n;
			vis[u] = 1;
			path.push_back(u);
		}

		for (int j : path) {
			int need = a[j] ^ cur;
			for (int i = 0; i < d; ++i)
				if (need >> i & 1) res += (char) ('0' + i);
			cur = a[j];
		}
	}

	cout << res.size() << '\n';
	for (auto c : res) cout << c << ' ';
}