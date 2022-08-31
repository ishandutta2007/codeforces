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

#define fst first
#define snd second
#define all(c) ((c).begin()), ((c).end())

const int INF = (1 << 20);
struct graph {
  struct edge {
    short src, dst;
    int capacity, flow;
    size_t rev;
  };
  int n;
  int flow;
  vector<vector<edge>> adj;
  graph(){flow = 0;}
  graph(int n) : n(n), adj(n), flow(0){ }
  void add_edge(int src, int dst, int capacity) {
    adj[src].push_back({src, dst, capacity, 0, adj[dst].size()});
    adj[dst].push_back({dst, src, 0, 0, adj[src].size()-1});
  }
  int max_flow(int s, int t) {
    vector<int> level(n), iter(n);
    function<int(void)> levelize = [&]() { // foward levelize
      level.assign(n, -1); level[s] = 0;
      queue<int> Q; Q.push(s);
      while (!Q.empty()) {
        int u = Q.front(); Q.pop();
        if (u == t) break;
        for (auto &e: adj[u]) {
          if (e.capacity > e.flow && level[e.dst] < 0) {
            Q.push(e.dst);
            level[e.dst] = level[u] + 1;
          }
        }
      }
      return level[t];
    };
    function<int(int, int)> augment = [&](int u, int cur) {
      if (u == t) return cur;
      for (int &i = iter[u]; i < adj[u].size(); ++i) {
        edge &e = adj[u][i], &r = adj[e.dst][e.rev];
        if (e.capacity > e.flow && level[u] < level[e.dst]) {
          int f = augment(e.dst, min(cur, e.capacity - e.flow));
          if (f > 0) {
            e.flow += f;
            r.flow -= f;
            return f;
          }
        }
      }
      return int(0);
    };
    // for (int u = 0; u < n; ++u) // initialize
    //   for (auto &e: adj[u]) e.flow = 0;

    // int flow = 0;
    while (levelize() >= 0) {
      fill(all(iter), 0);
      for (int f; (f = augment(s, INF)) > 0; )
        flow += f;
    }
    return flow;
  }
  void clr_all(){
	  vector<vector<edge>>().swap(adj);
  }
};

graph G[1 << 10];
int f[1 << 10];
bool done[1 << 10];
int sm[1 << 10], lowest[1 << 10];
const int N = 10030;
int A[N], B[N], W[N];
int main(){
	for(int i = 1; i < (1 << 10); i++){
		lowest[i] = (i & 1) ? 0 : (lowest[i >> 1] + 1);
	}
	int n, m, k, q;
	sd(n); sd(m); sd(k); sd(q);
	G[0] = graph(n);
	for(int i = 0; i < m; i++){
		sd(A[i]); sd(B[i]); sd(W[i]);
		A[i]--; B[i]--;
		if(i >= k) G[0].add_edge(A[i], B[i], W[i]);
	}
	f[0] = G[0].max_flow(0, n - 1);
	done[0] = 1;
	for(int i = 1; i <= k; i++){
		for(int j = 0; j < (1 << k); j++) if(__builtin_popcount(j) == i - 1){
			for(int r = 0; r < k; r++) if(!done[j | (1 << r)] && !(j >> r & 1)){
				int X = j | (1 << r);
				done[X] = 1;
				G[X] = G[j];
				G[X].add_edge(A[r], B[r], INF);
				f[X] = G[X].max_flow(0, n - 1);
			}
			G[j].clr_all();
		}
	}

	for(int i = 0; i < q; i++){
		for(int j = 0; j < k; j++) sd(W[j]);
		int total = (1 << k) - 1;
		int ans = f[total]; // none removed
		sm[0] = 0;
		for(int j = 1; j < (1 << k); j++){
			int r = lowest[j];
			sm[j] = sm[j ^ (1 << r)] + W[r];
			ans = min(ans, f[total ^ j] + sm[j]);
		}
		printf("%d\n", ans);
	}
}