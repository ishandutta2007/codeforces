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

struct point {
	int x, y;
	bool operator < (const point &o) const {
		return pair<int, int> (x, y) < pair<int, int> (o.x, o.y);
	}
} pt[N], hull[N];

// 0 --> Colinear
// 1 --> Clockwise
// 2 --> Counterclockwise

int n, m;

int ccw(point a, point b, point c) {
	int v = (b.y - a.y) * (c.x - b.x) -
			(b.x - a.x) * (c.y - b.y);
	return !v ? 0 : (v < 0 ? 1 : 2);
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, x, y; i <= n; i++)
		cin >> x >> y, pt[i] = {x, y - x * x};
	sort(pt + 1, pt + n + 1);
	for (int i = 1; i <= n; i++) {
		// cout << pt[i].x << ' ' << pt[i].y << '\n';
		if (i == n || pt[i + 1].x != pt[i].x) {
			// die
			while (m > 1 && ccw(hull[m - 1], hull[m], pt[i]) <= 1) -- m;
			hull[++ m] = pt[i];
		}
	}
	cout << m - 1;
}