#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define tab "\t"
#define endl "\n"

#define ferr std::cerr

#ifdef DEBUG
std::ifstream fin("in");
std::ofstream fout("out");
#else
#define fin std::cin
#define fout std::cout
#endif

const int mxn = 2e5 + 5;

int n;
int a[mxn], b[mxn];
std::vector <int> vec[mxn];
int in[mxn];
bool vis[mxn];
std::vector <int> adj[mxn];

inline void dfs(int u) {
	vis[u] = 1;
	for (int v : adj[u]) {
		if (!-- in[v]) {
			dfs(v);
		}
	}
}

inline void Main() {
	fin >> n;
	rep(i, n) fin >> a[i], -- a[i];
	rep(i, n) fin >> b[i], -- b[i];
	int ans = 0;
	rep(i, n) vec[i].clear();
	rep(i, n) vec[a[i]].push_back(i);
	rep(i, n) ans = std::max(ans, (int) vec[i].size());
	int p = -1;
	rep(i, n) if (!~p || vec[i].size() > vec[p].size()) p = i;
	rep(i, n) adj[i].clear(), in[i] = 0, vis[i] = 0;
	rep(i, n) if (a[i] != p && b[i] != p) adj[a[i]].push_back(b[i]), in[b[i]] += 1;
	rep(i, n) if (!in[i] && !vis[i]) dfs(i);
	bool flg = 1;
	rep(i, n) flg &= !in[i];
	fout << (flg ? "AC" : "WA") << endl;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	fin >> T;
	while (T --) Main();
	return 0;
}