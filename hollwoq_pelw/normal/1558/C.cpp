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

const int N = 2200;

int n, a[N], pos[N];
vector<int> res;

void do_rev(int p) {
	if (p == 1) return ;
	reverse(a + 1, a + p + 1);
	for (int i = 1; i <= p; i++)
		pos[a[i]] = i;
	res.push_back(p);
	// for (int i = 1; i <= n; i++)
	// 	cout << a[i] << " \n"[i == n];
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], pos[a[i]] = i;
	for (int i = 1; i <= n; i++)
		if (a[i] % 2 != i % 2)
			return cout << "-1\n", (void) 0;
	res.clear();
	for (int i = n; i > 1; i -= 2) {
		if (pos[i] == i && pos[i - 1] == i - 1)
			continue ;
		do_rev(pos[i]);
		// i first
		do_rev(pos[i - 1] - 1);
		// .. i, i - 1
		do_rev(pos[i - 1] + 1);
		// .. i - 1, i
		do_rev(pos[i]);
		// i, i - 1 ..
		do_rev(i);
	}
	cout << res.size() << '\n';
	for (auto v : res) 
		cout << v << ' ';
	cout << '\n';
}