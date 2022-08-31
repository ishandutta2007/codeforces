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

struct graph{
    vector<vector<int>> adj;
    int n;
    graph(){}
    graph(int n) : n(n), adj(n){}
    void add_edge(int a, int b){
        adj[a].push_back(b);
        adj[b].push_back(a);
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
};

const int N = 200005;
int perm[N], a[N];
int main(){
	int n, m, k;
	sd(n); sd(m); sd(k);
	graph g(n);
	for(int i = 0; i < k; i++){
		perm[i] = i;
		sd(a[i]); a[i]--;
	}
	for(int j = 0; j < m; j++){
		int u, v;
		scanf("%d %d", &u, &v);
		g.add_edge(u - 1, v - 1);
	}

	vector<int> d = g.distances(0), D = g.distances(n - 1);
	// trace(d, D);
	sort(perm, perm + k, [&](int i, int j){return d[a[i]] + D[a[j]] < d[a[j]] + D[a[i]];});
	int mx = -(1 << 30);
	int ans = -(1 << 30);
	for(int i = k - 1; i >= 0; i--){
		int node = a[perm[i]];
		// trace(node, mx, d[node]);
		ans = max(ans, mx + d[node] + 1);
		mx = max(mx, D[node]);
	}
	printf("%d\n", min(d[n - 1], ans));
}