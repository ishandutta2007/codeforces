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

vector<pair<int, int>> res;

int ok[N], pr[N], n;

struct __initial__ {
	__initial__ () {
		for (int i = 2; i < N; i++) pr[i] = 1;
		for (int i = 2; i < N; i++) {
			if (pr[i]) {
				for (int j = i * 2; j < N; j += i)
					pr[j] = 0;
			}
		}
	}
} __init__;

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 3; i * 2 <= n; i++) if (pr[i]) {
		vector<int> p(1, i); ok[i] = 1;
		for (int j = 3 * i; j <= n; j += i) 
			if (!ok[j]) p.push_back(j), ok[j] = 1;
		if (p.size() & 1)
			p.push_back(2 * i), ok[2 * i] = 1;

		for (int j = 0; j < p.size(); j += 2)
			res.emplace_back(p[j], p[j + 1]);
	}
	vector<int> p;
	for (int i = 2; i <= n; i += 2)
		if (!ok[i]) p.push_back(i);
	for (int j = 0; j + 1 < p.size(); j += 2)
		res.emplace_back(p[j], p[j + 1]);
	cout << res.size() << '\n';
	for (auto ij : res)
		cout << ij.first << ' ' << ij.second << '\n';
}