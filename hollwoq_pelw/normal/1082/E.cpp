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

const int N = 5e5 + 1;

int n, c, a[N], cntC[N], lst[N];

vector<int> vc[N];

inline int getcnt(int l, int r) {
    return cntC[r] - cntC[l - 1];
}

inline int solve(const vector<int> &v) {
    int res = -1e9, cur = 0;
    for (auto x : v)
        res = max(res, cur = max(cur + x, 0));
    return res;
}

void Hollwo_Pelw() {
    cin >> n >> c;
    for (int i = 1; i <= n; i++)
        cin >> a[i], cntC[i] = cntC[i - 1] + (a[i] == c);
    for (int i = 1; i <= n; i++) {
        vc[a[i]].push_back(-getcnt(lst[a[i]], i)), vc[a[i]].push_back(1), lst[a[i]] = i;
    }
    int res = 0;
    for (int i = 1; i < N; i++) if (i != c)  {
        vc[i].push_back(-getcnt(lst[i], n));
        res = max(res, solve(vc[i]));
    }
    cout << res + getcnt(1, n);
        
}