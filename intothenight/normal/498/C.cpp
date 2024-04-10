#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;
#define all(a) a.begin(), a.end()
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef tuple<int, int, int> tpl;
template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class T1, class T2>
istream &operator>>(istream &in, pair<T1, T2> &P){
	in >> P.first >> P.second;
	return in;
}
template<class T1, class T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &P){
	out << "(" << P.first << ", " << P.second << ")";
	return out;
}
template<class T>
istream &operator>>(istream &in, vector<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const vector<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
template<class T>
istream &operator>>(istream &in, deque<T> &arr){
	for(auto &x: arr) in >> x;
	return in;
}
template<class T>
ostream &operator<<(ostream &out, const deque<T> &arr){
	for(auto &x: arr) out << x << ' '; cout << "\n";
	return out;
}
mt19937 rnd(time(0));

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
	flownetwork(int n, int source, int sink):
		n(n), source(source), sink(sink){
		adj.resize(n);
		flow = 0;
	}
	void clear(){
		for(auto &e: edge) e.flow = 0;
		flow = 0;
	}
	int insert(int from, int to, T fcap, T bcap){
		int ind = edge.size();
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
	dinic(flownetwork<T> &_g):
		g(_g){
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
		if(u == g.sink) return w;
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
				ptr[i] = g.adj[i].size() - 1;
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vi a(n);
	cin >> a;
	vector<pii> edge(m);
	cin >> edge;
	vi prime;
	for(auto x: a){
		for(int p = 2; p * p <= x; p ++){
			if(x % p == 0){
				prime.push_back(p);
				while(x % p == 0) x /= p;
			}
		}
		if(x > 1){
			prime.push_back(x);
		}
	}
	sort(all(prime));
	prime.resize(unique(all(prime)) - prime.begin());
	int res = 0;
	for(auto p: prime){
		int source = 0, sink = n + 1;
		flownetwork<int> g(n + 2, source, sink);
		for(int i = 1; i <= n; i ++){
			int t = a[i - 1], e = 0;
			while(t % p == 0){
				e ++;
				t /= p;
			}
			if(e){
				if(i & 1){
					g.insert(source, i, e, 0);
				}
				else{
					g.insert(i, sink, e, 0);
				}
			}
		}
		for(auto [u, v]: edge){
			if(v & 1){
				swap(u, v);
			}
			g.insert(u, v, 1e9, 0);
		}
		dinic<int> d(g);
		res += d.max_flow();
	}
	cout << res;
	return 0;
}
/*
10 10
2 2 2 2 2 2 2 2 2 2
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 1
*/

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\\                                    //
//           +++`+``+`+`++++        ///`````````````````````````````\\                              //
//           ++`+`+``+++`++++  /////```````````````````````````````````\                            //
//           +++`++`+`+``+++/////`````````````````````````````````````````\                         //
//             +++`++`+``+///```````````|```````````````````````````````````\                       //
//          ____++++/++++/`````````````/````````|````````|```````````````````\                      //
//        /  /  / |    //``````````````|````````|```````|````````|````````````\                     //
//       /  /  /  | ///````````/```````|```````||```````|````````|``````\```````\                   //
//       | /  /   |///`````````|``````/````````|````````|````````|```````|```````\                  //
//       |/   |   |//``|```````|``````|````````|`````````|```````|```````|````````\                 //
//       /\___|__//`|``|```````|`    |      ``:|````````|:```````|```````|```|`````|                //
//      /     /  /``|``|``````|/     |        :|     ```:|```````|```````|``++````++                //
//     /     / //```|``|``````|      |        |:        :|    ```|```````|```++``++`\               //
//     |    /  /````|``|``````/    _.::::.    |          |      |    ````|```|`++`\`|               //
//     |   /   |````|``|`````|            `                    |       ``|```++``++`|               //
//     |  /    |````|``|`````|                                 :         |``++````++|               //
//     | /     /````|``|`````|                              _.-:::.      |..`|``.`|.|               //
//     |/     /`````|``|`````|                                     `     |```|````|`|               //
//    /|      |`````|``|`````|                    :'                    .|```|````|.|               //
//   / |      |`````|``|`````|                                         /|-|``|````|`|               //
//  /  |      |`````|```\````|                                        / ||```|````|``\              //
// /   |      |`````|````|```|::                                    /_| ||```|````|``|              //
//            |`````|````|```|:|:.        `.._                    .\___/:|```|````|``|              //
//            |`````\````|```|:|::-          ``:::....           -:|:|:::|```|````|``|              //
//            |``````|```|```|:|::`|.                          .:::|:|:::|```|````|``|              //
//             \`````|```|```|:|::/|--.                     .`:|:::|:|:::/```|````|``|              //
//              |````|```|```\:|:|:|-----             _..-:|:|:|:::|:|::|````|````|`/               //
//              |````|```|````\|:|:|-------.____.....------|/::|:::|:|::|````|````|`|               //
//              |````|```|\````\:|/\___________    ________/\--\:::|:|::|````/````|`|               //
//              |````\```| \```|:/-------------\  /----------\``\::|:|::|```/`````|`|               //
//              |`````|``|  \``|/---------------\/------------\_________|```|`````|`|               //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                        Created by Aeren                                          //
//                                                                                                  //
//////////////////////////////////////////////////////////////////////////////////////////////////////