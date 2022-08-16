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

template<class T,class U>
ostream& operator<<(ostream& os,const map<T, U> & mp){
	os << "{";
	int i = 0;
	for(auto it : mp){
		if(i) os<<", ";
		os << it;
		i++;
	}
	os << "}";	
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

const long long INF = (1ll << 50);
struct graph {
  typedef long long flow_type;
  struct edge {
    int src, dst;
    flow_type capacity, flow;
    size_t rev;
  };
  int n;
  vector<vector<edge>> adj;
  graph(int n) : n(n), adj(n) { }
  void add_edge(int src, int dst, flow_type capacity) {
    adj[src].push_back({src, dst, capacity, 0, adj[dst].size()});
    adj[dst].push_back({dst, src, 0, 0, adj[src].size()-1});
  }
  flow_type max_flow(int s, int t) {
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
    function<flow_type(int, flow_type)> augment = [&](int u, flow_type cur) {
      if (u == t) return cur;
      for (int &i = iter[u]; i < adj[u].size(); ++i) {
        edge &e = adj[u][i], &r = adj[e.dst][e.rev];
        if (e.capacity > e.flow && level[u] < level[e.dst]) {
          flow_type f = augment(e.dst, min(cur, e.capacity - e.flow));
          if (f > 0) {
            e.flow += f;
            r.flow -= f;
            return f;
          }
        }
      }
      return flow_type(0);
    };
    for (int u = 0; u < n; ++u) // initialize
      for (auto &e: adj[u]) e.flow = 0;

    flow_type flow = 0;
    while (levelize() >= 0) {
      fill(all(iter), 0);
      for (flow_type f; (f = augment(s, INF)) > 0; )
        flow += f;
    }
    return flow;
  }
};
const int N = 205;
int x1[N], Y1[N], x2[N], Y2[N];


int main(){
	int n, m;
	sd(n); sd(m);
	set<int> intx, inty;
	vector<pii> INTX, INTY;
	for(int i = 1; i <= m; i++){
		sd(x1[i]);
		sd(Y1[i]);
		sd(x2[i]);
		sd(Y2[i]);
		intx.insert(x1[i]);
		intx.insert(x2[i]);
		inty.insert(Y1[i]);
		inty.insert(Y2[i]);
	}
	
	int lst = 0;
	for(int x : intx){
		if(x -1 >= lst + 1)
			INTX.push_back({lst + 1, x - 1});
		INTX.push_back({x, x});
		lst =x;
	}
	lst = 0;

	for(int y : inty){
		if(y - 1 >= lst + 1)
			INTY.push_back({lst + 1, y - 1});
		INTY.push_back({y, y});
		lst = y;
	}
	graph g(sz(INTX) + sz(INTY) + 2);
	for(int i = 0; i < sz(INTX); i++){
		g.add_edge(0, i + 1, INTX[i].S - INTX[i].F + 1);
		for(int j = 0; j < sz(INTY); j++){
			for(int k = 1; k <= m; k++){
				if(x1[k] <= INTX[i].F && x2[k] >= INTX[i].S){
					if(Y1[k] <= INTY[j].F && Y2[k] >= INTY[j].S){
						// black
						g.add_edge(i + 1, sz(INTX) + j + 1, INF);
						break;
					}
				}
			}
		}
	}

	for(int i = 0; i < sz(INTY); i++){
		g.add_edge(sz(INTX) + i  + 1, sz(INTX) + sz(INTY) + 1, INTY[i].S - INTY[i].F + 1);
	}
	
	printf("%lld\n", g.max_flow(0, sz(INTX) + sz(INTY) + 1));
}