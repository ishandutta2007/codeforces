//misaka will carry me to master
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <cassert>
#include <algorithm>
#include <vector>
#include <functional>
#include <numeric>
#include <set>
#include <map>
#include <queue>

#define ll long long
#define lb long double
#define sz(vec) ((int)(vec.size()))
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define kill(x, s) {int COND = x; if(COND){ cout << s << "\n"; return ; }}

const lb eps = 1e-9;
//const ll mod = 1e9 + 7, ll_max = 1e18;
//const ll mod = (1 << (23)) * 119 +1, ll_max = 1e18;
const int MX = 5e2 +10, int_max = 0x3f3f3f3f;

struct {
  template<class T>
  operator T() {
    T x; std::cin >> x; return x;
  }
} in;

using namespace std;


const int max_v = MX;
int graph[max_v][max_v], flow[max_v][max_v];
int dep[max_v], vis[max_v];
int head[max_v];
vector<int> adj[max_v];
int n, m, src, dest;

bool bfs(){
  queue<int> q;
  q.push(src);
  memset(dep, 0x3f, sizeof(dep));
  memset(head, 0, sizeof(head));
  dep[src] = 0;
  while(!q.empty()){
    int u = q.front(); q.pop();
    if(u == dest) return 1;
    for(int i : adj[u]){
      if(graph[u][i] - flow[u][i] > 0ll && dep[i] > (long long)MX){
        dep[i] = dep[u] + 1;
        q.push(i);
      }
    }
  }
  
  return (dep[dest] < (long long)MX) ;
}

long long dfs(int u, long long cap){
  long long ans = 0ll;
  if(u == dest || cap == 0ll) return cap;
  for(int i = head[u]; i<adj[u].size(); i++,head[u]++){
    int v = adj[u][i];
    long long C = graph[u][v] - flow[u][v];
    if(u != v && dep[v] == dep[u] + 1 && C > 0ll){
      if(long long sent = dfs(v, min(cap, C))){
        flow[u][v] += sent;
        flow[v][u] -= sent;
        ans += sent;
        cap -= sent;
        return ans;
      }
    }
    
  }
  if(!ans) dep[u] = int_max;
  return ans;
}

long long dinics(){
  long long tot = 0ll;
  while(bfs()){
    while(true){
      long long sent = dfs(src, int_max);
      tot += (long long)sent;
      if(!sent) break;
    }
  }
  return tot;
}

void add(int u, int v, ll c){
	if(!c) return;
	if(!graph[u][v] && !graph[v][u]){
		adj[u].pb(v);
		adj[v].pb(u);
	}
	graph[u][v] += c;
	//graph[v][u] += c;

}	

void solve(){
	n = in, m =in;
	vector<int> a(n+1), b(n+1);
	int as = 0, bs = 0;
	for(int i = 1; i<=n; i++){
		a[i] = in;
		as += a[i];
	}
	for(int i = 1; i<=n; i++){
		b[i] = in;
		bs += b[i];
	}
	for(int i = 1; i<=m; i++){
		int a, b;
		cin >> a >> b;
		add(a, n+b, 101);
		add(b, n+a, 101);
	}
	kill(as^bs, "NO");
	int ssrc = 2*n +1, ssink = 2*n +2;
	src = ssrc, dest = ssink;
	for(int i = 1; i<=n; i++){
		add(ssrc, i, a[i]);
		add(i+n, ssink, b[i]);
		add(i, n+i, 101);
	}

	ll flows = dinics();
	//cout << flows << "\n";
	kill(flows != as, "NO");
	//kill(1, "Yes");
	cout << "YES\n";
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cout << flow[i][n+j] << " ";
		}
		cout << "\n";
	}
}	


int main(){
  cin.tie(0) -> sync_with_stdio(0);

  int T = 1;
  //cin >> T;
  for(int i = 1; i<=T; i++){
		solve();
	}
  return 0;
}