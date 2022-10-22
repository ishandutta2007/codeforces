#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void __init__();
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
	int testcases = 1; cin >> testcases;
	__init__();
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

const int N = 5e5 + 5;

string s;
int f[N];

void __init__() {
	for (int i = 1; i < 200; i++) {
		set<int> st;
		for (int j = 1; j < i; j++)
			st.insert(f[j - 1] ^ f[i - j - 1]);
		while (st.count(f[i])) f[i] ++;
	}
	for (int i = 200; i < N; i++)
		f[i] = f[i - 34];
}

void Hollwo_Pelw(){
	int n, a = 0, b = 0, res = 0;
	cin >> n >> s;
	a = count(s.begin(), s.end(), 'R');
	b = count(s.begin(), s.end(), 'B');
	
	if (a > b) return cout << "Alice\n", (void) 0;
	if (a < b) return cout << "Bob\n", (void) 0;

	for (int i = 0, j; i < n; i = j) {
		j = i + 1;
		while (j < n && s[j] != s[j - 1])
			j ++;
		res ^= f[j - i];
	}

	cout << (res ? "Alice\n" : "Bob\n");
}