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
	if (fopen(".inp", "r"))
		assert(freopen(".inp", "r", stdin)), assert(freopen(".out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

#define int long long

const int N = 2e5 + 5;

int n, m, a[N];

void Hollwo_Pelw(){
	priority_queue<int> pq;
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i < n; i++)
		pq.push(a[i + 1] - a[i] - 1);
	pq.push(m + a[1] - a[n] - 1);

	int res = 0, turn = 0;
	while (!pq.empty()) {
		int x = pq.top() - turn * 2; pq.pop();
		if (x >= 3) {
			turn += 2;
			res += x - 1;
		} else if (x >= 1) {
			turn ++;
			res += 1;
		}
	}
	cout << m - res << '\n';
}