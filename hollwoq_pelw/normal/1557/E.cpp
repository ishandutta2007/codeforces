#include <bits/stdc++.h>
using namespace std;

void FAST_IO(string filein = "", string fileout = ""){
	if (fopen(filein.c_str(), "r")){
		freopen(filein.c_str(), "r", stdin);
		freopen(fileout.c_str(), "w", stdout);
	}
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Why_Are_You_So_Orz();

signed main(){
#ifndef ONLINE_JUDGE
	FAST_IO("input.inp", "output.out");
	auto start = chrono::steady_clock::now();
#else
	FAST_IO("mike4235orz.inp", "mike4235orz.out");
#endif
	int testcases = 1;
	cin >> testcases;
	for (int test = 1; test <= testcases; test++)
		Why_Are_You_So_Orz();
#ifndef ONLINE_JUDGE
	auto end = chrono::steady_clock::now();
	cout << endl;
	cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

int cury = 0;
string s; 

inline bool get(string t) {
	return s.find(t) != string::npos;
}

inline void move(int x, int y) {
	cout << x << ' ' << y << endl;
	cury = y, cin >> s;
}

bool solve_row(int x) {
	if (cury == 8) {
		for (int y = 7; y; y--) {
			move(x, y);
			if (get("Done"))
				return 1;
			if (get("Up"))
				return solve_row(x);
			if (get("Down"))
				return 0;
		}
	} else {
		for (int y = (cury == 1 ? 2 : 1); y <= 8; y++) {
			move(x, y);
			if (get("Done"))
				return 1;
			if (get("Up"))
				return solve_row(x);
			if (get("Down"))
				return 0;
		}
	}
	return 0;
}

void Why_Are_You_So_Orz() {
	cury = 1;
	for (int x = 1; x <= 8; x++) {
		move(x, cury);
		if (get("Done"))
			return ;
		if (solve_row(x))
			return ;
	}
}