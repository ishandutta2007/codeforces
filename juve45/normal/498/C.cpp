#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

void debug_out() { cerr << endl; }
template<class T> ostream& prnt(ostream& out, T v) { out << v.size() << '\n'; for(auto e : v) out << e << ' '; return out;}
template<class T> ostream& operator<<(ostream& out, vector <T> v) { return prnt(out, v); }
template<class T> ostream& operator<<(ostream& out, set <T> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, map <T1, T2> v) { return prnt(out, v); }
template<class T1, class T2> ostream& operator<<(ostream& out, pair<T1, T2> p) { return out << '(' << p.st << ' ' << p.nd << ')'; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H; debug_out(T...);}

#define dbg(...) cerr << #__VA_ARGS__ << " ->", debug_out(__VA_ARGS__)
#define dbg_v(x, n) do{cerr<<#x"[]: ";for(int _=0;_<n;++_)cerr<<x[_]<<" ";cerr<<'\n';}while(0)
#define dbg_ok cerr<<"OK!\n"

const int N = 20105;
const int INF = 0x3f3f3f3f;
const int Source = N - 3;
const int Sink = N - 2;

struct edge {
  int to, flow;
};

int i, ptr[N], dist[N], q[N], a[N], n, m, x, y;
vector<int> lda[N];
vector<edge> E;
vector <pair<int, int> > edges;
set <int> primes;


void clearNetwork() {
  E.clear();
  for(int i = 0; i < N; ++i) lda[i].clear();
}

void addEdge(int x, int y, int flow) {
	// dbg(x, y, flow);
  E.push_back({y, flow});
  E.push_back({x, 0});
  lda[x].push_back(E.size() - 2);
  lda[y].push_back(E.size() - 1);
}

bool bfs() {
  int st = 0, dr = 0;
  memset(dist, INF, sizeof(dist));
  for(q[st] = Source, dist[Source] = 0; st <= dr; ++st)
    for(int it : lda[q[st]])
      if(E[it].flow && dist[E[it].to] > dist[q[st]] + 1) {
        dist[E[it].to] = dist[q[st]] + 1;
        q[++dr] = E[it].to;
      }
  return dist[Sink] != INF;
}

int dfs(int x, int flow) {
  if(!flow || x == Sink) return flow;
  for(; ptr[x] < lda[x].size(); ++ptr[x]) {
    int it = lda[x][ptr[x]];
    if(E[it].flow <= 0 || dist[E[it].to] != dist[x] + 1) continue;
    int pushed = dfs(E[it].to, min(flow, E[it].flow));
    if(pushed) {
      E[it].flow -= pushed;
      E[it ^ 1].flow += pushed;
      return pushed;
    }
  }
  return 0;
}

int dinic() {
  int flow = 0;
  while(bfs()) {
    memset(ptr, 0, sizeof(ptr));
    while(int pushed = dfs(Source, INF)) flow += pushed;
  }
  return flow;
}

void desc(int nr, set <int> & primes) {
	for(int j = 2; j * j <= nr; j++) {
		if(nr % j == 0) {
			primes.insert(j);
			while(nr % j == 0) nr /= j;
		}
	}
	if(nr != 1) primes.insert(nr);
}

int nr(int k, int d) {
	int ret = 0;
	while(k % d == 0) k /= d, ret++;
	return ret;
}

int main() {

	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		desc(a[i], primes);
	}

	for(int i = 1; i <= m; i++) {
		cin >> x >> y;
		if(x % 2 == 0) swap(x, y);
		edges.push_back({x, y});
	}

	int cnt = 0;
	for(auto j : primes) {
		addEdge(Source, cnt * (n + 1), 1e9);
		for(int i = 1; i <= n; i+= 2)
			addEdge(cnt * (n + 1), cnt * (n + 1) + i, nr(a[i], j));
		for(int i = 2; i <= n; i+= 2)
			addEdge(cnt * (n + 1) + i, Sink, nr(a[i], j));
		for(auto i : edges)
			addEdge(cnt * (n + 1) + i.st, cnt * (n + 1) + i.nd, 1e9);
		cnt++;
	}	
	cout << dinic() << '\n';

  return 0;
}