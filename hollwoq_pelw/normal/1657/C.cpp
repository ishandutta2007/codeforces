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

void Hollwo_Pelw(){
	int n; string s; 
 
	cin >> n >> s;
 
	int c = 0, r = n;
 
	for (int i = 0, j; i < n; ) {
		if (i == n - 1)
			break ;
		if (s[i] == ')' && s[i + 1] == '(') {
			for (j = i + 1; j < n && s[j] == '('; j++);
 
			if (j == n)
				break ;
 
			r -= j - i + 1;
			i = j + 1;
			c ++;
		} else {
			i += 2;
			r -= 2;
			c ++;
		}
	}
 
	cout << c << ' ' << r << '\n';
}