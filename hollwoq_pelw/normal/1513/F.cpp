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

#define min __min__
#define max __max__

__attribute__((always_inline)) int min(int a, int b) { return a > b ? b : a; }
__attribute__((always_inline)) int max(int a, int b) { return a < b ? b : a; }
__attribute__((always_inline)) void smin(int &a, int b) { a = a > b ? b : a; }

const int N = 1 << 18;
int n, a[N], b[N], la[N], lb[N], l, sa[N], sb[N], s;

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > b[i]) {
			la[l] = a[i], lb[l ++] = b[i], sum += a[i] - b[i];
		} else {
			sa[s] = a[i], sb[s ++] = b[i], sum += b[i] - a[i];
		}
	}
	int res = 0, ta, tb;
	for (int i = 0; i < l; i++) {
		ta = la[i], tb = lb[i];
		for (int j = 0; j < s; j++) {
			smin(res, max(sa[j], tb) - min(sb[j], ta));
		}
	}
	cout << sum + 2ll * res;
}