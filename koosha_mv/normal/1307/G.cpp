#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<(x.F)<<" , "<<x.S<<"}"<<endl
#define eror(x) cout<<#x<<'='<<(x)<<endl
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define f(i,a,b) for(int i=a;i<b;i++)
#define nb(x) __builtin_popcount(x)
#define all(v) v.begin(),v.end()
#define bit(n,k) (((n)>>(k))&1)
#define Add(x,y) x=(x+y)%mod
#define maxm(a,b) a=max(a,b)
#define minm(a,b) a=min(a,b)
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=55,inf=2e9;
const long double d=1;

int n,m,q,ans[N];

struct Flew {
   struct Edge {
      int to;
   	int cap;
   	int cost;
      int id;
      Edge () : to(), cap(), cost(), id() {}
      Edge (int _to, int _cap, int _cost, int _id) : to(_to), cap(_cap), cost(_cost), id(_id) {}
   };
   int n,MaxFlow;
   vector< Edge > E;
   vector< vector<int> > G;
   vector< int > par, use;
   vector< int > dis, pot;
	
	Flew(int _n) : n(_n), use(_n, 0), pot(_n, 0){
      G.resize(_n);
      dis.resize(_n);
      par.resize(_n);
   }
   void AddEdge(int u, int v, int cap, int cost, int id = -1){
   	G[u].push_back((int) E.size());
      E.push_back({v, cap, cost, id});
      G[v].push_back((int) E.size());
      E.push_back({u, 0, -cost, id});
   }
   pair<int, int> Push(int src, int snk){
   	fill(dis.begin(), dis.end(), numeric_limits<int>::max() / 10);
      fill(par.begin(), par.end(), -1);
   	fill(use.begin(), use.end(), 0);
      priority_queue<pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq;
      dis[src] = 0; pq.push({dis[src], src});
 
      int fr;
      while(!pq.empty()){
         fr = pq.top().S; pq.pop();
      	if(use[fr]) continue;
         use[fr] = 1;
         for(auto id : G[fr]){
      		if(E[id].cap == 0) continue;
         	int w = E[id].cost + pot[fr] - pot[E[id].to];
         	if(dis[ E[id].to ] > dis[fr] + w){
            	dis[ E[id].to ] = dis[fr] + w;
               pq.push({dis[ E[id].to ], E[id].to});
            	par[ E[id].to ] = id;
            }
         }
      }
 
   	if(use[snk] == 0) return {0, 0};
 
   	for(int i = 0; i < n; i++) pot[i] += dis[i];
   	int mn = numeric_limits<int>::max();
      for(int u = snk; ~par[u]; u = E[par[u] ^ 1].to) mn = min(mn, E[par[u]].cap);
      for(int u = snk; ~par[u]; u = E[par[u] ^ 1].to) E[par[u]].cap -= mn, E[par[u]^1].cap += mn;
      return {mn, pot[snk]};
   }
 
	void MinCost(int src, int snk){
		pair<int, int> res, tot = {0, 0};
   	while((res = Push(src, snk)).F > 0){
			tot.S += res.F * res.S;
			tot.F += res.F;
			MaxFlow +=1;
			ans[tot.F] = tot.S;
      }
   }
};


int main(){
	Flew Flow(N);
	cin>>n>>m;
	f(i,0,m){
		int u,v,w;
		cin>>u>>v>>w;
		Flow.AddEdge(u,v,1,w);
	}
	Flow.MinCost(1,n);
	cin>>q;
	f(t,0,q){
		int x;
		long double res=inf;
		cin>>x;
		f(i,1,Flow.MaxFlow+1){
			minm(res,(d*x+ans[i])/(d*i));
		}
		cout<<fixed<<setprecision(10)<<res<<endl;
	}
}