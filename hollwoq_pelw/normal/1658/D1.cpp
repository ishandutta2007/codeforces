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

const int N = 1 << 17;

int l, r, a[N], b[N], mn[N], mx[N];

void solve_max(int bt, const vector<int> &p, const vector<int> &q) {
	if (bt < 0) {
		for (int i : q) mx[i] = b[i] ^ a[p[0]];
		return ;
	}
	vector<int> np[2], nq[2];
	for (int i : p)
		np[a[i] >> bt & 1].push_back(i);
	for (int i : q)
		nq[b[i] >> bt & 1].push_back(i);
	
	if (np[0].empty() || np[1].empty())
		return solve_max(bt - 1, p, q);

	for (int i = 0; i < 2; i++) {
		solve_max(bt - 1, np[i ^ 1], nq[i]);
	}
}

void solve_min(int bt, const vector<int> &p, const vector<int> &q) {
	if (bt < 0) {
		for (int i : q) mn[i] = b[i] ^ a[p[0]];
		return ;
	}
	vector<int> np[2], nq[2];
	for (int i : p)
		np[a[i] >> bt & 1].push_back(i);
	for (int i : q)
		nq[b[i] >> bt & 1].push_back(i);

	if (np[0].empty() || np[1].empty())
		return solve_min(bt - 1, p, q);
	
	for (int i = 0; i < 2; i++) {
		solve_min(bt - 1, np[i], nq[i]);
	}
}

void Hollwo_Pelw(){
	cin >> l >> r;
	for (int i = 0; i <= r - l; i++) {
		cin >> a[i], b[i] = a[i] ^ l;
	}
	vector<int> q(r - l + 1), p(r - l + 1);
	iota(q.begin(), q.end(), 0);
	iota(p.begin(), p.end(), 0);

	solve_min(16, p, q);
	solve_max(16, p, q);

	for (int i = 0; i <= r - l; i++)
		if (mn[i] == l && mx[i] == r)
			return cout << b[i] << '\n', (void) 0;

	cout << "-1\n";
	assert(0);
}