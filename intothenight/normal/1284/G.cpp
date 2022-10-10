#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

struct Bond_Matroid{
	int n, m, ecnt;
	vector<string> s;
	vector<vector<vector<array<int, 3>>>> adj;
	vector<array<int, 4>> edge;
	vector<int> active;
	vector<vector<int>> vis;
	Bond_Matroid(auto s, auto adj, auto edge): n(int(s.size())), m(int(s[0].size())), ecnt(int(edge.size())), s(s), adj(adj), edge(edge), active(ecnt, true), vis(n, vector<int>(m)){

	}
	bool independent_with(int e){
		for(auto i = 0; i < n; ++ i){
			fill(vis[i].begin(), vis[i].end(), false);
		}
		deque<pair<int, int>> q{{0, 0}};
		vis[0][0] = true;
		while(!q.empty()){
			auto [x, y] = q.front();
			q.pop_front();
			for(auto [nx, ny, ne]: adj[x][y]){
				if(active[ne] && ne ^ e && !vis[nx][ny]){
					vis[nx][ny] = true;
					q.push_back({nx, ny});
				}
			}
		}
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				if(s[i][j] == 'O' && !vis[i][j]){
					return false;
				}
			}
		}
		return true;
	}
	void insert(int e){
		active[e] = false;
	}
	void clear(){
		fill(active.begin(), active.end(), true);
	}
};
struct Partition_Matroid{
	int n, m;
	vector<string> s;
	vector<array<int, 4>> edge;
	vector<vector<int>> deg, cnt;
	Partition_Matroid(auto s, auto edge, auto deg): n(int(s.size())), m(int(s[0].size())), s(s), edge(edge), deg(deg), cnt(deg){

	}
	bool independent_with(int e){
		auto [x, y, nx, ny] = edge[e];
		if(nx + ny & 1){
			return (!x && !y) || cnt[x][y] > 2;
		}
		else{
			return cnt[nx][ny] > 2;
		}
	}
	void insert(int e){
		auto [x, y, nx, ny] = edge[e];
		-- cnt[x][y], -- cnt[nx][ny];
	}
	void clear(){
		cnt = deg;
	}
};
// to get answer just call Matroid_Intersection<M1, M2, T>(m1, m2, ground).solve()
// rebuild() = O(r^2) insert() and clear() calls
// test() = O(1) independent_with() calls
// O(r) rebuild() + O(r*n) test() = O(r^3) (insert() + clear()) + O(r*n) independent_with() calls in total
template<class M1, class M2, class T>
struct Matroid_Intersection{
	Matroid_Intersection(M1 m1, M2 m2, const std::vector<T> &ground): n((int) ground.size()), m1(m1), m2(m2), ground(ground), present(ground.size()), except1(n, m1), except2(n, m2){
		// greedy step
		for(int i = 0; i < n; ++ i){
			if(test(m1, i) && test(m2, i)){
				present[i] = true;
				m1.insert(ground[i]), m2.insert(ground[i]);
			}
		}
		rebuild();
		// augment step
		while(augment());
	}
	std::vector<T> solve(){
		std::vector<T> ans;
		for(int i = 0; i < n; ++ i){
			if(present[i]){
				ans.push_back(ground[i]);
			}
		}
		return ans;
	}
	int n;
	std::vector<T> ground;
	std::vector<bool> present;
	M1 m1;
	M2 m2;
	vector<M1> except1;
	vector<M2> except2;
	template<class M>
	bool test(M &m, int add, int rem = -1){
		if(present[add] || rem != -1 && !present[rem]) return false;
		return m.independent_with(ground[add]);
	}
	void rebuild(){
		m1.clear(), m2.clear();
		for(int u = 0; u < n; ++ u){
			if(present[u]){
				m1.insert(ground[u]), m2.insert(ground[u]);
			}
		}
		for(int u = 0; u < n; ++ u){
			if(present[u]){
				except1[u].clear(), except2[u].clear();
				for(int v = 0; v < n; ++ v){
					if(v != u && present[v]){
						except1[u].insert(ground[v]), except2[u].insert(ground[v]);
					}
				}
			}
		}
	}
	bool augment(){
		std::deque<int> q;
		std::vector<int> dist(n, -1);
		std::vector<int> frm(n, -1);
		for(int i = 0; i < n; ++ i){
			if(test(m1, i)){
				q.push_back(i);
				dist[i] = 0;
			}
		}
		if(q.empty()){
			return false;
		}
		while(!q.empty()){
			int on = q.front();
			q.pop_front();
			for(int i = 0; i < n; ++ i){
				if(dist[i] == -1 && (dist[on] % 2 == 0 ? test(except2[i], on, i) : test(except1[on], i, on))){
					q.push_back(i);
					dist[i] = dist[on] + 1;
					frm[i] = on;
					if(test(m2, i)){
						for(int pos = i; pos != -1; pos = frm[pos]){
							present[pos] = !present[pos];
						}
						rebuild();
						return true;
					}
				}
			}
		}
		return false;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int tt;
	cin >> tt;
	while(tt --){
		int n, m;
		cin >> n >> m;
		vector<string> s(n);
		int tot = 0;
		for(auto i = 0; i < n; ++ i){
			cin >> s[i];
			for(auto &c: s[i]){
				tot += c == 'O';
			}
		}
		vector<vector<vector<array<int, 3>>>> adj(n, vector<vector<array<int, 3>>>(m));
		vector<array<int, 4>> edge;
		vector<vector<int>> deg(n, vector<int>(m));
		for(auto i = 0; i < n; ++ i){
			for(auto j = 1; j < m; ++ j){
				if(s[i][j - 1] == 'O' && s[i][j] == 'O'){
					int e = int(edge.size());
					adj[i][j - 1].push_back({i, j, e});
					adj[i][j].push_back({i, j - 1, e});
					++ deg[i][j - 1];
					++ deg[i][j];
					edge.push_back({i, j - 1, i, j});
				}
			}
		}
		for(auto i = 1; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				if(s[i - 1][j] == 'O' && s[i][j] == 'O'){
					int e = int(edge.size());
					adj[i - 1][j].push_back({i, j, e});
					adj[i][j].push_back({i - 1, j, e});
					++ deg[i - 1][j];
					++ deg[i][j];
					edge.push_back({i - 1, j, i, j});
				}
			}
		}
		int ecnt = int(edge.size());
		vector<int> ground(ecnt);
		iota(ground.begin(), ground.end(), 0);
		vector<int> res = Matroid_Intersection(Bond_Matroid(s, adj, edge), Partition_Matroid(s, edge, deg), ground).solve();
		bool ok = true;
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				if((i || j) && (i + j) % 2 == 0 && deg[i][j] == 1){
					ok = false;
				}
			}
		}
		if(ok && int(res.size()) == ecnt - (tot - 1)){
			vector<string> grid(2 * n - 1, string(2 * m - 1, 'O'));
			for(auto i = 0; i < n; ++ i){
				for(auto j = 0; j < m; ++ j){
					grid[2 * i][2 * j] = s[i][j];
				}
			}
			for(auto i = 1; i < n; ++ i){
				for(auto j = 1; j < m; ++ j){
					grid[2 * i - 1][2 * j - 1] = ' ';
				}
			}
			for(auto e: res){
				auto [x, y, nx, ny] = edge[e];
				if(x == nx){
					grid[2 * x][2 * y + 1] = ' ';
				}
				else{
					grid[2 * x + 1][2 * y] = ' ';
				}
			}
			cout << "YES\n";
			for(auto s: grid){
				cout << s << "\n";
			}
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////