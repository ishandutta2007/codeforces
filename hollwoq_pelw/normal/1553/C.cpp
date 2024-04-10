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

#define int long long

string s;

int solve(int c) {
	string t = s;
	for (int i = 0; i < 10; i++) {
		if (t[i] == '?') {
			t[i] = (c ^ i & 1) + '0';
		}
	}
	// cout << t << '\n';
	int cnt[2] = {0, 0}, lef[2] = {5, 5};
	for (int i = 0; i < 10; i++) {
		cnt[i & 1] += t[i] - '0';
		lef[i & 1] --;
		if (cnt[i & 1] + lef[i & 1] < cnt[i & 1 ^ 1])
			return i + 1;
		if (cnt[i & 1 ^ 1] + lef[i & 1 ^ 1] < cnt[i & 1])
			return i + 1;
	}
	return 10;	
}

void Hollwo_Pelw() {
	cin >> s;
	cout << min(solve(0), solve(1)) << '\n';
}