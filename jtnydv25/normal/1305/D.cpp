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

int query(int x, int y){
	printf("? %d %d\n", x, y);
	fflush(stdout);
	int v; sd(v);
	return v;
}
struct graph{
    vector<vector<int>> adj;
	vector<int> done;
    int n;
    graph(){}
    graph(int n) : n(n), adj(n), done(n){}
    void add_edge(int a, int b, bool directed = false){
        adj[a].push_back(b);
        if(!directed) adj[b].push_back(a);
    }
	int getLast(int s){
		const int INF = 1e9;
		vector<int> D(n, INF); D[s] = 0; 
		queue<int> q; q.push(s);
		int lst = s;
		while(!q.empty()){
			int u = q.front(); q.pop();
			lst = u;
			int d = D[u];
			for(int v : adj[u]) if(D[v] == INF && !done[v]){
				D[v] = d + 1;
				q.push(v);
			}
		}
		return lst;
	}
	void input(int m, int ind = 1, bool directed = false){
        for(int i = 0; i < m; i++){
            int u, v;
            // confirm weights fit into integers
            scanf("%d %d", &u, &v);
            add_edge(u - ind, v - ind, directed);
        }
    }
	void removeBad(int x, int y, int l){
		vector<int> badParent(n, 0);
		vector<int> vis(n, 0);
		function<void(int, int)> dfs1 = [&](int s, int p){
			vis[s] = 1;
			if(s == x || s == y){
				// trace(p);
				badParent[p] = 1;
			}
			for(int v : adj[s]) if(!vis[v]){
				dfs1(v, s == l ? v : p);
			}
		};
		function<void(int, int)> dfs2 = [&](int s, int p){
			// trace(s, p);
			vis[s] = 1;
			if(s != l && badParent[p]){
				// trace(s);
				done[s] = 1;
			}
			for(int v : adj[s]){
				// trace(s, v, vis[v]);
				if(!vis[v]){
					dfs2(v, s == l ? v : p);
				}
			}
		};
		dfs1(l, -1);
		fill(all(vis), 0);
		dfs2(l, -1);
	}
	void go(){
		while(1){
			int rem = count(all(done), 0);
			// trace(rem);
			if(rem == 1){
				printf("! %d\n", 1 + (int)(find(all(done), 0) - done.begin()));
				return;
			}
			for(int i = 0; i < n; i++) if(!done[i]){
				int j = getLast(i);
				int k = getLast(j);
				int l = query(j + 1, k + 1) - 1;
				if(l == j){
					printf("! %d\n", j + 1);
					return;
				}
				if(l == k){
					printf("! %d\n", k + 1);
					return;
				}
				// trace(j, k, l);
				removeBad(j, k, l);
				break;
			}
		}
	}
};
int main(){
	int n; sd(n);
	graph g(n);
	g.input(n - 1, 1);
	g.go();
}