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
	cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = chrono::steady_clock::now();
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 3e5 + 5;

int n, cnt[N], a[N];

void Hollwo_Pelw() {
	cin >> n;
	fill(cnt + 1, cnt + n + 1, 0);
	string s(n, '0');

	for (int i = 1; i <= n; i++)
		cin >> a[i], cnt[a[i]] ++;

	for (int i = 1, l = 1, r = n; i <= n; i++) {
		if (cnt[i] == 0) break ;
		s[n - i] = '1';
		if (cnt[i] > 1 || (a[l] != i && a[r] != i)) break ;
		(a[l] == i ? l ++ : r --);
	}

	s[0] = '1';
	for (int i = 1; i <= n; i++)
		if (cnt[i] != 1) s[0] = '0';
	cout << s << '\n';
}