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

const int N = 3.5e4 + 5;

struct point {
	int x, y;
	point (int _x = 0, int _y = 0)
		: x(_x), y(_y) {}
	bool operator < (const point& o) const {
		return 1ll * x * o.y < 1ll * y * o.x;
	}
	point operator - () const {
		return point(-x, y);
	}
};

vector<point> up, dw; 

int n, c, d, num_lf, num_rt;
int64_t res, cnt_lf, cnt_rt;

void Hollwo_Pelw() {
	cin >> n >> c >> d;
	for (int i = 1, r, w; i <= n; i++) {
		cin >> r >> w, r -= c, w -= d;
		if (w < 0) dw.emplace_back(r, -w);
		if (w > 0) up.emplace_back(r, +w);
		if (w == 0) 
			(r > 0 ? num_lf : num_rt) ++;
	}
	sort(up.begin(), up.end());
	sort(dw.begin(), dw.end());

	for (auto p : up) {
		int l = lower_bound(dw.begin(), dw.end(), - p) - dw.begin();
		int r = upper_bound(dw.begin(), dw.end(), - p) - dw.begin();

		res += 1ll * l * (dw.size() - r);

		cnt_lf += l;
		cnt_rt += dw.size() - r;
	}

	for (auto p : dw) {
		int l = lower_bound(up.begin(), up.end(), - p) - up.begin();
		int r = upper_bound(up.begin(), up.end(), - p) - up.begin();

		res += 1ll * l * (up.size() - r);
	}

	cout << res + cnt_lf * num_lf + cnt_rt * num_rt; 
}