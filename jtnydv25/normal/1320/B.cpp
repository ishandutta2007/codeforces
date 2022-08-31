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
template<class T>
struct graph{
    vector<vector<int>> adj;
	vector<vector<int>> radj;
    int n;
    graph(){}
    graph(int n) : n(n), adj(n), radj(n){}
    void add_edge(int a, int b, bool directed = false){
        adj[a].push_back(b);
		radj[b].push_back(a);
        if(!directed) adj[b].push_back(a);
    }
	vector<int> distances(int s){
		const int INF = 1e9;
		vector<int> D(n, INF); D[s] = 0; 
		queue<int> q; q.push(s);
		while(!q.empty()){
			int u = q.front(); q.pop();
			int d = D[u];
			for(int v : adj[u]) if(D[v] == INF){
				D[v] = d + 1;
				q.push(v);
			}
		}
		return D;
	}
	void input(int m, int ind = 1, bool directed = false){
        for(int i = 0; i < m; i++){
            int u, v;
            // confirm weights fit into integers
            scanf("%d %d", &u, &v);
            add_edge(v - ind, u - ind, directed);
        }
    }
};

int p[200005];
int num[200005];
int main(){
    int n, m, k;
    scanf("%d %d", &n, &m);
    graph<int> g(n);
    g.input(m, 1, true);
    sd(k);
	for(int i = 1; i <= k; i++){
		sd(p[i]); p[i]--;
	}
	vector<int> dist = g.distances(p[k]);
	for(int i = 0; i < n; i++){
		int d = dist[i];
		for(int j : g.radj[i]) if(dist[j] == d - 1){
			num[i]++;
		}
	}
	int mn = 0, mx = 0;
	for(int i = 1; i < k; i++){
		// p[i] -> p[i + 1]
		if(dist[p[i]] == dist[p[i + 1]] + 1){
			if(num[p[i]] > 1){
				mx++;
			}
		} else{
			mn++; mx++;
		}
	}
	printf("%d %d\n", mn, mx);
}