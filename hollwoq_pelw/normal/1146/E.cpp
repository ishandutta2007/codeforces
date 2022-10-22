/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

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

const int N = 1 << 17, S = 1 << 11;

int n, q, x[N], a[N];	
bitset<N> t;

void Hollwo_Pelw() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int _ = 0; _ < q; _++) {
		char c; cin >> c >> x[_], t[_] = c == '>';
	}
	for (int j = 0; j < n; j += S) {
		for (int k = 0; k < q; k++) {
			if (t[k])
				for (int i = j; i < j + S; i++)
					a[i] = (a[i] > x[k] ? - a[i] : a[i]);
			else
				for (int i = j; i < j + S; i++)
					a[i] = (a[i] < x[k] ? - a[i] : a[i]);
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
}