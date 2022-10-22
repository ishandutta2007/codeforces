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

#define int long long
const int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

const int M = 155, N = 35;

int n, a[N], res;
bool mark[M << 1][M << 1];
bool vis[M << 1][M << 1][N][8];

struct node {
	int x, y, f, d;
	node () {}
	node (int _x, int _y, int _f, int _d) 
		: x(_x), y(_y), f(_f), d(_d) { }
};

queue<node> q;

void bfs() {
	vis[M][M][1][0] = 1;
	q.emplace(M, M, 1, 0);

	while (!q.empty()) {
		auto tmp = q.front(); q.pop();
		int x = tmp.x, y = tmp.y, f = tmp.f, d = tmp.d;
		for (int i = 0; i < a[f]; i++) {
			x += dx[d], y += dy[d];
			mark[x][y] = 1;
		}
		if (f == n) continue ;
		if (!vis[x][y][f + 1][d + 1 & 7]) {
			vis[x][y][f + 1][d + 1 & 7] = 1;
			q.emplace(x, y, f + 1, d + 1 & 7);
		} 
		if (!vis[x][y][f + 1][d + 7 & 7]) {
			vis[x][y][f + 1][d + 7 & 7] = 1;
			q.emplace(x, y, f + 1, d + 7 & 7);
		}
	}
}

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	bfs();

	for (int i = 0; i < M << 1; i++)
		for (int j = 0; j < M << 1; j++)
			res += mark[i][j];
	cout << res;
}