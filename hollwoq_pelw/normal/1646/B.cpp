/*-------------------------------/ 
      hollwo_pelw's template     
/-------------------------------*/

#include <bits/stdc++.h>
// #include <ext/push_back_ds/assoc_container.hpp>
// #include <ext/push_back_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_push_backds;
// using namespace __gnu_cxx;

void FAST_IO(string filein = "", string fileout = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
#endif
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
	return 0;
}

const int N = 2e5 + 5;

#define int long long

int n, a[N];

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + n + 1);
	
	int s = 0, e = 0;

	for (int i = 1, j = n; i <= j; ) {
		s += a[i ++];
		if (s < e)
			return cout << "YES\n", (void) 0;
		e += a[j --];
	}

	cout << "NO\n";
}