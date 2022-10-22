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

#define int long long

int solve(int a, int b) {
	string x = to_string(a), y = to_string(b);
	int r = x.size() + y.size();
	for (int i = 0, j = 0; i < x.size(); i++) {
		if (j < y.size() && y[j] == x[i])
			r -= 2, j++;
	}
	return r;
}

void Why_Are_You_So_Orz() {
	int res = 1e9, n; cin >> n;
	for (int i = 0; i <= 60; i++) {
		res = min(res, solve(n, 1ll << i));
	}
	cout << res << '\n';
}