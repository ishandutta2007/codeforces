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

int n, d, a[N], b[N];

void Hollwo_Pelw() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		b[i] = a[i] - a[i - 1] - 1;

	multiset<int> st;
	for (int i = 1; i <= n; i++)
		st.insert(b[i]);

	int res = *st.begin();

	for (int i = 1; i < n; i++) {
		st.erase(st.find(b[i]));
		st.erase(st.find(b[i + 1]));

		st.insert(b[i] + b[i + 1] + 1);
		// insert to last
		res = max(res, min(*st.begin(), d - a[n] - 1));
		// insert to max
		auto it = -- st.end();
		res = max(res, min(*st.begin(), (*it - 1) / 2));

		st.erase(st.find(b[i] + b[i + 1] + 1));

		st.insert(b[i]);
		st.insert(b[i + 1]);
	}

	st.erase(st.find(b[n]));
	st.insert(d - a[n - 1] - 1);
	res = max(res, *st.begin());

	cout << res << '\n';
}