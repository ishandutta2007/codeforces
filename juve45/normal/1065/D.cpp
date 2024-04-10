#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << p.st << ' ' << p.nd; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 12;
int n, a;
int dist[3][N][N][N][N];
int dx[] = {1, 2, -1, -2, 1, 2, -1, -2};
int dy[] = {2, 1, -2, -1, -2, -1, 2, 1};
pair <int, int> pos[N * N], dp[N * N][3];

bool valid(int x, int y) {
	if(x <= 0 || y <= 0) return 0;
	if(x > n || y > n) return 0;
	return 1;
}

void bfs(int x, int y, int mat[N][N]) {
	queue <pair<int, int> > q;
	memset(mat, 0x3f, N * N * 4);
	q.push({x, y});
	mat[x][y] = 0;
	while(!q.empty()) {
		auto p = q.front(); q.pop();
		for(int i = 0; i < 8; i++) {
			if(valid(p.st + dx[i], p.nd + dy[i]) && mat[p.st + dx[i]][p.nd + dy[i]] > mat[p.st][p.nd] + 1) {
				q.push({p.st + dx[i], p.nd + dy[i]});
				mat[p.st + dx[i]][p.nd + dy[i]] = mat[p.st][p.nd] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);	
	cin >> n;
	for(int i = 1; i <= n; i++) 
		for(int j = 1; j <= n; j++)
			cin >> a, pos[a] = {i, j};

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			bfs(i, j, dist[0][i][j]);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int ii = 1; ii <= n; ii++)
				for(int jj = 1; jj <= n; jj++)
					dist[1][i][j][ii][jj] = 2 - (i == ii || j == jj);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			for(int ii = 1; ii <= n; ii++)
				for(int jj = 1; jj <= n; jj++)
					if((i + j) % 2 == (ii + jj) % 2)
						dist[2][i][j][ii][jj] = 2 - (i + j == ii + jj || i - j == ii - jj);
					else
						dist[2][i][j][ii][jj] = 10000;

	dp[1][0] = {0, 0};
	dp[1][1] = {0, 0};
	dp[1][2] = {0, 0};
	for(int i = 2; i <= n * n; i++) {
		dp[i][0] = dp[i][1] = dp[i][2] = {1e9, 1e9};
		for(int last = 0; last <= 2; last++)
			for(int curr = 0; curr <= 2; curr++) {
				auto p = dp[i - 1][last];
				int d = dist[curr][pos[i - 1].st][pos[i - 1].nd][pos[i].st][pos[i].nd];
				
				for(int x = 1; x <= n; x++)
					for(int y = 1; y <= n; y++)
						d = min(d, dist[last][pos[i - 1].st][pos[i - 1].nd][x][y] + dist[curr][x][y][pos[i].st][pos[i].nd]);

				p.st += d;
				p.st += (last != curr);
				p.nd += (last != curr);
				dp[i][curr] = min(p, dp[i][curr]);
			}
	}
	// dbg(dp[2][0]);
	// dbg(pos[2], pos[3]);
	// dbg(dist[0][3][2][1][3]);
	// dbg(dp[3][0]);
	// dbg(dp[4][1]);
	// for(int i = 1; i <= n * n; i++)
	// 	dbg(i, dp[i][0], dp[i][1], dp[i][2]);
	cout << min({dp[n * n][0], dp[n * n][1], dp[n * n][2]}) << '\n';

}