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
typedef pair<ll, int> pli;
typedef vector<string> vs;
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

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	const int S = 26 * 26 * 26;
	auto trans = [&](string s){
		return (s[0] - 'A') + (s[1] - 'A') * 26 + (s[2] - 'A') * 26 * 26;
	};
	int n;
	cin >> n;
	vi cnt(S);
	vector<pii> data(n);
	for(int i = 0; i < n; i ++){
		string s, t;
		cin >> s >> t;
		string x({s[0], s[1], s[2]}), y({s[0], s[1], t[0]});
		cnt[trans(x)] ++;
		data[i] = {trans(x), trans(y)};
	}
	int source = n + S, sink = n + S + 1;
	flownetwork<int> f(2 + n + S, source, sink);
	for(int i = 0; i < n; i ++){
		f.insert(source, i, 1, 0);
		if(cnt[data[i].first] == 1) f.insert(i, n + data[i].first, 1, 0);
		f.insert(i, n + data[i].second, 1, 0);
	}
	for(int i = 0; i < S; i ++){
		f.insert(n + i, sink, 1, 0);
	}
	dinic<int> d(f);
	if(d.max_flow() == n){
		cout << "YES\n";
		for(auto e: f.edge){
			if(e.from < n && e.flow == 1){
				int x = e.to - n;
				for(int i = 0; i < 3; i ++){
					cout << (char) (x % 26 + 'A');
					x /= 26;
				}
				cout << "\n";
			}
		}
	}
	else{
		cout << "NO";
	}
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                                  //
//                                                                                                  //
//                                              _____________                                       //
//             ++++++++++                ___------------------\\\\                                  //
//           +++`+``+`+`++++        ///`````````````````````````````\\\                             //
//           ++`+`+``+++`++++  /////```````````````````````````````````\\                           //
//           +++`++`+`+``+++/////`````````````````````````````````````````\\                        //
//             +++`++`+``+///```````````|```````````````````````````````````\\                      //
//          ____++++/++++/`````````````/````````|````````|```````````````````\\                     //
//        /  /  / |    //``````````````|````````|```````|````````|````````````\\                    //
//       /  /  /  | ///````````/```````|```````||```````|````````|``````\```````\\                  //
//       | /  /   |///`````````|``````/````````|````````|````````|```````|```````\\                 //
//       |/   |   |//``|```````|``````|````````|`````````|```````|```````|````````\\                //
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