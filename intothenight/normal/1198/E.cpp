#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace chrono;
#define all(a) a.begin(), a.end()
#define sz(x) (int(x.size()))
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef vector<string> vs;
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}

// Debug Functions
template<class T>
void print(vector<T> arr){
	cout << "-------------------------------------------------------------\nArray: ";
	cout << arr;
	cout << "-------------------------------------------------------------\n";
}
template<class T>
void print(vector<vector<T>> arr){
	cout << "-------------------------------------------------------------\nArray: \n";
	for(auto x: arr){
		cout << " ";
		cout << x;
	}
	cout << "-------------------------------------------------------------\n";
}
template<class T1, class T2>
void print(vector<pair<T1, T2>> arr){
	cout << "-------------------------------------------------------------\nArray: ";
	for(auto x: arr){
		cout << "(" << x.first << ", " << x.second << ") ";
	}
	cout << "\n-------------------------------------------------------------\n";
}
template<class T1, class T2>
void print(vector<vector<pair<T1, T2>>> arr){
	cout << "-------------------------------------------------------------\nArray: \n";
	for(auto x: arr){
		cout << " ";
		for(auto y: x){
			cout << "(" << y.first << ", " << y.second << ") ";
		}
		cout << "\n";
	}
	cout << "-------------------------------------------------------------\n";
}

template<class T>
struct flownetwork{
	static constexpr T eps = (T)1e-9;
	int n;
	vector<vector<int>> adj;
	struct edge{
		int from, to;
		T capacity, flow;
	};
	vector<edge> edge;
	int source, sink;
	T flow;
	flownetwork(int n, int source, int sink): n(n), source(source), sink(sink){
		adj.resize(n);
		flow = 0;
	}
	void clear(){
		for(auto &e: edge){
			e.flow = 0;
		}
		flow = 0;
	}
	int insert(int from, int to, T fcap, T bcap){
		int ind = sz(edge);
		adj[from].push_back(ind);
		edge.push_back({from, to, fcap, 0});
		adj[to].push_back(ind + 1);
		edge.push_back({to, from, bcap, 0});
		return ind;
	}
};
template<class T>
struct dinic{
	static constexpr T INF = numeric_limits<T>::max();
	flownetwork<T> &g;
	vector<int> ptr, level, q;
	dinic(flownetwork<T> &_g): g(_g){
		ptr.resize(g.n), level.resize(g.n), q.resize(g.n);
	}
	bool bfs(){
		fill(all(level), -1);
		q[0] = g.sink;
		level[g.sink] = 0;
		int beg = 0, end = 1;
		while(beg < end){
			int i = q[beg ++];
			for(auto ind: g.adj[i]){
				auto &e = g.edge[ind];
				auto &re = g.edge[ind ^ 1];
				if(re.capacity - re.flow > g.eps && level[e.to] == -1){
					level[e.to] = level[i] + 1;
					if(e.to == g.source){
						return true;
					}
					q[end ++] = e.to;
				}
			}
		}
		return false;
	}
	T dfs(int u, T w){
		if(u == g.sink){
			return w;
		}
		int &j = ptr[u];
		while(j >= 0){
			int ind = g.adj[u][j];
			auto &e = g.edge[ind];
			if(e.capacity - e.flow > g.eps && level[e.to] == level[u] - 1){
				T F = dfs(e.to, min(e.capacity - e.flow, w));
				if(F > g.eps){
					g.edge[ind].flow += F;
					g.edge[ind ^ 1].flow -= F;
					return F;
				}
			}
			j --;
		}
		return 0;
	}
	T max_flow(){
		while(bfs()){
			for(int i = 0; i < g.n; i ++){
				ptr[i] = sz(g.adj[i]) - 1;
			}
			T sum = 0;
			while(1){
				T add = dfs(g.source, INF);
				if(add <= g.eps){
					break;
				}
				sum += add;
			}
			if(sum <= g.eps){
				break;
			}
			g.flow += sum;
		}
		return g.flow;
	}
	vector<bool> min_cut(){
		max_flow();
		vector<bool> res(g.n);
		for(int i = 0; i < g.n; i ++){
			res[i] = (level[i] != -1);
		}
		return res;
	}
};
typedef tuple<int, int, int, int> rect;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<rect> a(m);
	vi X{0, n}, Y{0, n};
	const ll INF = 2e18;
	for(auto &[lx, ly, ux, uy]: a){
		cin >> lx >> ly >> ux >> uy, lx --, ly --;
		X.push_back(lx), Y.push_back(ly), X.push_back(ux), Y.push_back(uy);
	}
	sort(all(X)), sort(all(Y)), X.resize(unique(all(X)) - X.begin()), Y.resize(unique(all(Y)) - Y.begin());
	int nx = sz(X) - 1, ny = sz(Y) - 1;
	int source = nx + ny, sink = nx + ny + 1;
	flownetwork<ll> g(nx + ny + 2, source, sink);
	for(int i = 0; i < nx; i ++){
		g.insert(source, i, X[i + 1] - X[i], 0);
	}
	for(int i = 0; i < ny; i ++){
		g.insert(nx + i, sink, Y[i + 1] - Y[i], 0);
	}
	for(int i = 0; i < nx; i ++){
		for(int j = 0; j < ny; j ++){
			auto pred = [&](const rect &arg){
				auto [lx, ly, ux, uy] = arg;
				return lx <= X[i] && X[i + 1] <= ux && ly <= Y[j] && Y[j + 1] <= uy;
			};
			if(any_of(all(a), pred)){
				g.insert(i, nx + j, INF, 0);
			}
		}
	}
	dinic<ll> d(g);
	cout << d.max_flow();
	return 0;
}