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

const int N = 1e5 + 5;
#define int long long

vector<int> p[65];

int n, a[N];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		for (int j = 60; j >= 0; j--)
			if (x >> j & 1) {
				p[j].push_back(x);
				break ;
			}
	}
	for (int i = 1, cur = 0; i <= n; i++) {
		bool ok = 0;
		for (int j = 0; j <= 60; j++) {
			if (!(cur >> j & 1) && !p[j].empty()) {
				a[i] = p[j].back();
				cur ^= a[i];
				p[j].pop_back();
				ok = 1;
				break ;
			}
		}
		if (!ok)
			return cout << "No\n", (void) 0;
	}
	cout << "Yes\n";
	for (int i = 1; i <= n; i++)
		cout << a[i] << ' ';
}