#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 3005;
int n, d[N][N], a, b, m;
int ans;
vector <int> nodes, v[N], c[N], c2[N];
int use[N];

void upd(vector <int> &c, int nxt, int node) {
	if(c.size() < 3) c.push_back(nxt);
	if(d[node][c[0]] < d[node][nxt]) c[1] = c[0], c[2] = c[1], c[0] = nxt;
	else if(d[node][c[1]] < d[node][nxt]) c[2] = c[1], c[1] = nxt;
	else if(d[node][c[2]] < d[node][nxt]) c[2] = nxt;
}

void bfs(int node) {
	memset(use, 0, sizeof use);
	use[node] = 1;
	d[node][node] = 0;
	queue <int> q;
	q.push(node);

	while(!q.empty()) {
		int x=  q.front(); q.pop();

		for(auto i : v[x])
			if(!use[i]) {
				d[node][i] = d[node][x] + 1;
				q.push(i);
				use[i] = 1;
			}
	}
}

void upd_ans(int val, int s1, int s2, int s3, int s4) {
	if(ans < val) {
		ans = val;
		nodes = {s1, s2, s3, s4};
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	memset(d, 0x3f, sizeof d);

	cin >> n >> m;
	for(int i = 1; i <= m;i++) {
		cin >> a >> b;
		v[a].push_back(b);
		// v[b].push_back(a);
	}

	for(int i = 1; i <= n; i++)
		bfs(i);

	for(int i = 1; i <= n; i++) {
		vector <pair<int, int> > dst;
		for(int j = 1; j <= n; j++)
			if(i != j && d[i][j] <= n)
				dst.push_back({d[i][j], j});
		sort(dst.begin(), dst.end(), greater <pair<int, int>>());

		// dbg(i, dst);
		for(int j = 0; j < min(5, (int)dst.size()); j++)
			c[i].push_back(dst[j].nd);
	}

	for(int i = 1; i <= n; i++) {
		vector <pair<int, int> > dst;
		for(int j = 1; j <= n; j++)
			if(i != j && d[j][i] <= n)
				dst.push_back({d[j][i], j});

		sort(dst.begin(), dst.end(), greater <pair<int, int>>());
		// dbg(i, dst);
		for(int j = 0; j < min(5, (int)dst.size()); j++)
			c2[i].push_back(dst[j].nd);
	}

	// dbg(d[4][6]);
	// dbg(c[1]);
	// dbg(c2[1]);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(i != j && d[i][j] <= n) {
				for(auto k1 : c2[i])
					for(auto k2 : c[j]) {
						if(k1 != k2 && k1 != j && k2 != i) {
							upd_ans(d[k1][i] + d[i][j] + d[j][k2], k1, i, j, k2);
						}
					}
			}
	assert(ans <= 3 * n);
	cout << nodes << '\n';
}