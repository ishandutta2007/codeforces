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

const int N = 505;


void check(string s, int &r, string t) {
	int v = -1, p = 0;

	int x = s.rfind(t[1]);
	if (x == string::npos)
		return ;
	s.erase(x, 1);

	v += s.size() - x;

	int y = s.rfind(t[0]);
	if (y == string::npos)
		return ;

	v += s.size() - y;
	while (s[p] == '0' && p < s.size()) p++, v++;

	if (r == -1 || r > v) r = v;
}

void Hollwo_Pelw() {
	string s;
	int res = -1;
	cin >> s;
	check(s, res, "00");
	check(s, res, "25");
	check(s, res, "50");
	check(s, res, "75");
	cout << res;
}