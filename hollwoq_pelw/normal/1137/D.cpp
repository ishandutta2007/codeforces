/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

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
	// cin >> testcases;
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

int grp[10];

int query(vector<int> q) {
	cout << "next";
	for (auto v : q)
		cout << ' ' << v;
	cout << endl;
	int k; cin >> k;
	for (int i = 1; i <= k; i++) {
		string s; cin >> s;
		for (auto c : s)
			grp[c - '0'] = i;
	}
	return k;
}

void Hollwo_Pelw() {
	while (1) {
		query({0, 1});
		query({0});
		if (grp[0] == grp[1])
			break ;
	}
	while (1) {
		if (query({0, 1, 2, 3, 4, 5, 6, 7, 8, 9}) == 1)
			break ;
	}
	cout << "done" << endl;
}