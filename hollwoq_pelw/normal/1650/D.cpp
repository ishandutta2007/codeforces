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

const int N = 2005;

void Hollwo_Pelw() {
	int n; cin >> n;
	deque<int> dq;
	for (int i = 1, x; i <= n; i++)
		cin >> x, dq.push_back(-- x);

	vector<int> res(n);
	
	for (int i = n; i --; ) {
		while (dq.back() != i) {
			dq.push_back(dq.front());
			dq.pop_front();
			++ res[i];
		}
		dq.pop_back();
	}

	for (int i = 0; i < n; i++)
		cout << res[i] << ' ';
	cout << '\n';
}