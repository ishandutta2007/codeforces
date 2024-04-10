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
	cout << "\nExcution time : " << chrono::duration_cast<
		chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 1e6 + 5;

int n, c, cnt[N];

inline bool have(int l, int r) {
	return cnt[min(r, c)] > cnt[l - 1];
}

void Hollwo_Pelw() {
	cin >> n >> c;
	fill(cnt + 1, cnt + c + 1, 0);
	for (int i = 1, a; i <= n; i++)
		cin >> a, cnt[a] = 1;
	for (int i = 1; i <= c; i++)
		cnt[i] += cnt[i - 1];

	for (int i = 1; i <= c; i++) if (have(i, i)) {
		for (int j = i; j <= c; j += i) {
			if (have(j, j + i - 1))
				if (!have(j / i, j / i))
					return cout << "No\n", (void) 0;
		}
	}
	cout << "Yes\n";
}