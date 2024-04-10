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

const int N = 303, inf = 2e9;

int n, m, p;

inline int dist(int sx, int sy, int ex, int ey) {
	return abs(sx - ex) + abs(sy - ey);
}

struct node {
	int x, y, d;
	bool operator < (const node &oth) const {
		return d < oth.d;
	}
};

vector<node> v[N * N];

void Hollwo_Pelw() {
	cin >> n >> m >> p;
	for (int i = 1; i <= n; i++)
		for (int j = 1, a; j <= m; j++)
			cin >> a, v[a].push_back({i, j, inf});
	for (auto &nd : v[1])
		nd.d = dist(1, 1, nd.x, nd.y);
	for (int i = 2; i <= p; i++) {
		sort(v[i - 1].begin(), v[i - 1].end());
		if (v[i - 1].size() > n + m)
			v[i - 1].resize(n + m);
		for (auto j : v[i - 1]) for (auto &k : v[i])
			k.d = min(k.d, j.d + dist(j.x, j.y, k.x, k.y));
	}
	cout << v[p][0].d;
}