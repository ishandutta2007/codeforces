#include <bits/stdc++.h>
using namespace std;

#define ll long long
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
const int mod = 998244353;
const int K = 40;
const ll INF = 1LL << 40;


template<class T>
struct weighted_graph{
    vector<vector<pair<int, T>>> adj;
    int n;
    weighted_graph(){}
    weighted_graph(int n) : n(n), adj(n){}
    void add_edge(int a, int b, T w, bool directed = false){
        adj[a].push_back({b, w});
        if(!directed) adj[b].push_back({a, w});
    }
	vector<T> distances(vector<int> ss){
        vector<T> dist(n, numeric_limits<T>::max() / 2);
		priority_queue<pair<T, int>,vector<pair<T, int>>, greater<pair<T, int>> > Q; 
		for(int s : ss){
			dist[s] = 0;
        	Q.push(pair<T, int>(0,s));
		}
        while(!Q.empty()) {
            pair<T, int> top = Q.top();
            Q.pop();
            T d = top.first;
            int v = top.second;
            if(d <= dist[v]) {
                for(auto it : adj[v]){
                    int v2 = it.first;
                    T cost = it.second;
                    if(dist[v2] > dist[v] + cost) {
                        dist[v2] = dist[v] + cost;
                        Q.push(pair<T, int>(dist[v2], v2));
                    }
                }
            }
        }
        return dist;
	}
};
const int N = 200005;
const ll INF2 = 1LL << 60;
ll dist[200005];
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	weighted_graph<ll> g(2 * n);
	vector<vector<int>> adj(n), rdj(n);
	fill(dist, dist + N, INF2);
	dist[0] = 0;
	for(int i = 0; i < n; i++){
		g.add_edge(2 * i, 2 * i + 1, INF);
	}
	for(int i = 0; i < m; i++){
		int u, v;
		cin >> u >> v;
		u--; v--;
		adj[u].push_back(v);
		rdj[v].push_back(u);
		g.add_edge(2 * v, 2 * u, 1, 1);
		g.add_edge(2 * u + 1, 2 * v + 1, 1, 1);
	}

	ll ans = INF2;
	for(int i = 0; i < K; i++){
		priority_queue<pair<ll, int>,vector<pair<ll, int>>, greater<pair<ll, int>> > Q;
		for(int j = 0; j < n; j++){
			Q.push(pair<ll, int>(dist[j], j));
		}

		while(!Q.empty()) {
            pair<ll, int> top = Q.top();
            Q.pop();
            ll d = top.first;
            int v = top.second;
            if(d <= dist[v]) {
				const vector<int> & V = i & 1 ? rdj[v] : adj[v];
                for(int pos = 0; pos < V.size(); pos++){
					int v2 = V[pos];
                	ll cost = 1;
                    if(dist[v2] > dist[v] + cost) {
                        dist[v2] = dist[v] + cost;
                        Q.push(pair<ll, int>(dist[v2], v2));
                    }
                }
            }
        }
		ans = min(ans, dist[n - 1] + (1LL << i) - 1);
	}
	
	if(ans != INF2){
		cout << ans << endl;
		return 0;
	}
	
	vector<ll> D = g.distances({2 * n - 2, 2 * n - 1});
	ll d2 = INF2;
	for(int i = 0; i < n; i++){	
		d2 = min(d2, D[2 * i + (K & 1)] + dist[i]);
	}
	assert(d2 < INF2);
	int R = d2 / INF + K;
	ll rem = d2 % INF;
	int v = 1;
	for(int j = 0; j < R; j++) v = (v * 2) % mod;
	cout << (v - 1 +  rem) % mod << endl;
}