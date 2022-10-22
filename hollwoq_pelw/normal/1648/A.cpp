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
	cout << "\nExcution time : " << chrono::duration_cast<
		chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 1e5 + 5;

#define int long long

int n, m;
vector<int> posx[N], posy[N];

inline int solve(vector<int> &v) {
	sort(v.begin(), v.end());
	int res = 0;
	for (int i = 1; i < (int) v.size(); i++) {
		res += (v[i] - v[i - 1]) * i * (v.size() - i);
	}
	return res;
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int x; cin >> x;
			posx[x].push_back(i);
			posy[x].push_back(j);
		}
	int res = 0;
	for (int i = 1; i < N; i++) {
		res += solve(posx[i]);
		res += solve(posy[i]);
	}
	cout << res << '\n';
}