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

int n, a[101], b[101];

map<vector<int>, int> mp; 

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 0, x; i < n; i++) {
		cin >> x, b[i] = x >> 15, a[i] = x & ((1 << 15) - 1);
	}
	for (int i = 0; i < (1 << 15); i++) {
		vector<int> v(n);
		for (int j = 0; j < n; j++)
			v[j] = __builtin_popcount(b[j] ^ i);
		mp[v] = i;
	}
	for (int i = 0; i < (1 << 15); i++) {
		vector<int> v(n), rv(n);
		for (int j = 0; j < n; j++)
			v[j] = __builtin_popcount(a[j] ^ i);
		for (int j = 0; j <= 16; j++) {
			for (int k = 0; k < n; k++)
				rv[k] = j - v[k];
			if (mp.count(rv)) {
				return cout << (mp[rv] << 15 | i), (void) 0;
			}
		}
	}
	cout << -1;
}