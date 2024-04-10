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

const int N = 1010, S = 64, mod = 998244353;

inline int add(int a, int b) {
	return a + b >= mod ? a + b - mod : a + b;
}

inline int mul(int a, int b) {
	return 1ll * a * b % mod;
}

inline int comp(int a, int b, int c) {
	return a << 4 | b << 2 | c;
}

struct Mat {
	int a[S][S];
	Mat () {
		memset(a, 0, sizeof a);
	}
	int* operator [] (int x) {return a[x];}
	const int* operator [] (int x) const {return a[x];}
	friend Mat operator * (const Mat& a, const Mat& b){
		Mat r;
		for (int i = 0; i < S; i ++)
			for (int j = 0; j < S; j ++){
				r[i][j] = 0;
				for (int k = 0; k < S; k ++)
					r[i][j] = add(r[i][j], mul(a[i][k], b[k][j]));
			}
		return r;
	}
} nor[32], col[3];

struct Vec : Mat {
	friend Vec operator * (const Vec &a, const Mat &b) {
		Vec r;
		for (int i = 0; i < 1; i ++)
			for (int j = 0; j < S; j ++){
				r[i][j] = 0;
				for (int k = 0; k < S; k ++)
					r[i][j] = add(r[i][j], mul(a[i][k], b[k][j]));
			}
		return r;
	}
};

int n, q, f[3][3], g[3], vis[4];

vector<pair<int, int>> pos[N];

void Hollwo_Pelw() {
	cin >> n;
	for (int i = 1, a; i <= n; i++) 
		cin >> a, pos[i].emplace_back(a, -1);
	
	cin >> q;
	for (int i = 1, p, x, c; i <= q; i++)
		cin >> p >> x >> c, pos[p].emplace_back(x, c - 1);
	
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> f[i][j];

	for (int i = 0; i < 3; i++) 
		for (g[0] = 0; g[0] < 4; g[0]++) 
			for (g[1] = 0; g[1] < 4; g[1]++) 
				for (g[2] = 0; g[2] < 4; g[2]++) {
					for (int j = 0; j < 4; j++) vis[j] = 0;
					for (int j = 0; j < 3; j++) vis[g[j]] |= f[i][j];
					for (int j = 0; j < 4; j++) if (!vis[j]) {
						col[i][comp(g[0], g[1], g[2])][comp(j, g[0], g[1])] = 1;
						break ; 
					}
				}

	for (int i = 0; i < S; i++) for (int j = 0; j < S; j++)
		nor[0][i][j] = col[0][i][j] + col[1][i][j] + col[2][i][j];
	
	for (int i = 1; i < 32; i++) nor[i] = nor[i - 1] * nor[i - 1];

	vector<int> ans = {1, 0, 0, 0};
	
	for (int p = 1; p <= n; p++) {
		int lst = 0;
		Vec res;
		res[0][comp(3, 3, 3)] = 1;
		
		sort(pos[p].begin(), pos[p].end());
		for (auto v : pos[p]) {
			int x = v.first, c = v.second, d = x - lst - (v != pos[p].back());
			for (int i = 31; i >= 0; i--)
				if (d >> i & 1)
					res = res * nor[i];
			if (c >= 0)
				res = res * col[c];
			lst = x;
		}

		vector<int> ways(4, 0), nxt(4, 0);
		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 4; y++)
				for (int z = 0; z < 4; z++) {
					ways[x] = add(ways[x], res[0][comp(x, y, z)]);
				}

		for (int i = 0; i < 4; i++) 
			for (int j = 0; j < 4; j++)
				nxt[i ^ j] = add(nxt[i ^ j], mul(ans[i], ways[j]));
		ans = nxt;
	}
	cout << ans[0];
}