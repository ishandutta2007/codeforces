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
	// cin >> testcases;
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

const int N = 2005;

int d[N][N], n, ok = 1;

void Hollwo_Pelw() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> d[i][j];
        ok &= d[i][i] == 0;
    }
    
    for (int i = 1; i <= n && ok; i++)
        for (int j = 1; j < i && ok; j++)
            if (d[i][j] != d[j][i] || (d[i][j] == 0)) ok = 0;
    
    for (int i = 1; i <= n && ok; i++) {
        int x = 1;
        for (int j = 1; j <= n; j++)
            if (i != j && d[i][j] < d[i][x]) x = j;
        // cout << d[i][x] << '\n';
        for (int j = 1; j <= n && ok; j++)
            if (abs(d[i][j] - d[j][x]) != d[i][x]) ok = 0;
    }
    
    cout << (ok ? "YES" : "NO");
}