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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool query(int a, int b, int c) {
	cout << "? " << a << ' ' << b << ' ' << c << endl;
	string res; cin >> res; return res[0] == 'Y';
}

int get(int n, int k) {
	int c = 0, t = 1, h = 0;
	while (c < n)
		c += t, h ++, t *= k;
	return h;
}

int n, k;

void Hollwo_Pelw() {
	cin >> n >> k;
	int h = get(n, k);
	vector<int> r;
	for (int _ = 0; _ < (60 * n - 4 * h * h) / (n - 2); _++) {
		int x = 0, y = 0;
		while (x == y)
			x = rng() % n + 1, y = rng() % n + 1;
		r.clear();
		for (int i = 1; i <= n; i++)
			if (i != x && i != y)
				if (query(x, i, y)) r.push_back(i);
		if (r.size() == 2 * h - 3) {
			for (auto a : r) {
				int c = 0;
				for (auto b : r) 
					if (b != a) c += query(x, b, a);
				if (c == h - 2)
					return cout << "! " << a << endl, (void) 0;
			}
		}
	}
}