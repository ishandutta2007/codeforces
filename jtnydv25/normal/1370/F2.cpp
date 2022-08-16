#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define pii pair<int, int>
#define F first
#define S second
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())
#define ld long double

template<class T,class U>
ostream& operator<<(ostream& os,const pair<T,U>& p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

template<class T>
ostream& operator <<(ostream& os,const vector<T>& v){
	os<<"{";
	for(int i = 0;i < (int)v.size(); i++){
		if(i)os<<", ";
		os<<v[i];
	}
	os<<"}";
	return os;
}

#ifdef LOCAL
#define cerr cout
#else
#endif

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

char feedback[10];
struct graph{
    vector<vector<int>> adj;
    int n;
    graph(){}
    graph(int n) : n(n), adj(n){}
    void add_edge(int a, int b, bool directed = false){
        adj[a].push_back(b);
        if(!directed) adj[b].push_back(a);
    }

	pii query(vector<int> nodes){
		printf("? %d ", sz(nodes));
		for(int v : nodes) printf("%d ", v + 1);
		printf("\n");
		fflush(stdout);
		int x, y; sd(x); sd(y);
		return {y, x - 1};
	}

	vector<vector<int>> atDepth;
	void go(){
		vector<int> par(n);
		const int INF = 1 << 30;
		vector<int> dist(n, INF);
		function<int(int, bool)> farthest = [&](int s, bool get){
			atDepth.clear();
			queue<int> q;
			dist.assign(n, INF);
			dist[s] = 0;
			q.push(s);
			int lst;
			while(!q.empty()){
				int u = q.front();
				if(get){
					if(sz(atDepth) <= dist[u]){
						atDepth.resize(dist[u] + 1);
					}
					atDepth[dist[u]].push_back(u);
				}
				lst = u;
				q.pop();
				for(int v : adj[u]) if(dist[v] == INF){
					dist[v] = dist[u] + 1;
					par[v] = u;
					q.push(v);
				}
			}
			return lst;
		};
		int x = farthest(farthest(0, false), false);
		int c = x;
		for(int i = 1; 2 * i <= dist[x]; i++) c = par[c];
		farthest(c, true);
		vector<int> ALL(n); iota(all(ALL), 0);
		int D = query(ALL).first;
		int lo = 0, hi = atDepth.size() - 1;
		assert(hi - lo < 510);
		int deepest = c, depth = 0;
		while(lo < hi){
			int mid = (lo + hi + 1) >> 1;
			vector<int> ask;
			for(int d = mid; d < sz(atDepth); d++) copy(all(atDepth[d]), back_inserter(ask));
			auto DD = query(ask);
			if(DD.F == D){
				lo = mid;
				if(mid > depth){
					depth = mid;
					deepest = DD.S;
				}
			} else{
				hi = mid - 1;
			}
		}
		int node = deepest;
		farthest(node, true);
		int node2 = query(atDepth[D]).S;
		printf("! %d %d\n", node + 1, node2 + 1);
		fflush(stdout);
		scanf("%s", feedback);
	}
	void input(int ind = 1, bool directed = false){
		int m = n - 1;
        for(int i = 0; i < m; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            add_edge(u - ind, v - ind, directed);
        }
    }
};

int main(){
	int t; sd(t);
	while(t--){
		int n; sd(n);
		graph T(n);
		T.input();
		T.go();
	}
}