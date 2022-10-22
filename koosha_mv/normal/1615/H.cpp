#include <bits/stdc++.h>
using namespace std;
#define dbgv(v) cout<<#v<<" = "; f(i,0,v.size()) cout<<v[i]<<" "; cout<<endl
#define dbga(a,x,y) cout<<#a<<" = "; f(i,x,y) cout<<a[i]<<" "; cout<<endl
#define erorp(x) cout<<#x<<"={"<<x.F<<" , "<<x.S<<"}"<<endl
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

const int inf=1e9;

struct F{
  struct Edge{
  	int to , cap;
  };
  int s , t;
  vector<Edge> E;
	vector<vector<int>> adj;
  vector<int> dist , ptr;
 
  void init(int n){
    E.clear(); adj.clear(); dist.clear(); ptr.clear();
    adj.resize(n); dist.resize(n); ptr.resize(n);
  }
 
	void addEdge(int v , int u , int cap){
    adj[v].push_back(E.size()); E.push_back({u , cap});
    adj[u].push_back(E.size()); E.push_back({v , 0});
  }
 
  int BFS(){
    fill(all(ptr) , 0);
    fill(all(dist) , inf);
    queue<int> Q;
    dist[s] = 0;
    Q.push(s);
    while(!Q.empty()){
      int v = Q.front(); Q.pop();
      for(int i : adj[v]){
        if(E[i].cap == 0)   continue;
        if(dist[E[i].to] != inf)    continue;
        dist[E[i].to] = dist[v] + 1;
        Q.push(E[i].to);
      }
    }
    return (dist[t] != inf);
  }
 
  int DFS(int v , int f = inf){
    if(v == t)  return f;
    int ans = 0;
    for( ; ptr[v] < adj[v].size() ; ptr[v]++){
      int i = adj[v][ptr[v]];
      if(dist[E[i].to] != dist[v] + 1 || E[i].cap == 0) continue;
      int flow = min(f , E[i].cap);
      int res = DFS(E[i].to , flow);
      ans += res; f -= ans;
      E[i].cap -= res;
      E[(i ^ 1)].cap += res;
      if(f == 0)  break;
    }
    return ans;
  }
 
  int maxFlow(int _s , int _t){
    s = _s; t = _t;
    int ans = 0;
    while(BFS()){
      ans += DFS(s);
    }
    return ans;
  }
} flow;

const int N=1010;

int n,m,a[N],s[N],t[N],ans[N],mark[N];
vector<int> vec;

void solve(int l,int r,vector<int> p){
	if(l==r){
		for(auto x : p){
			ans[x]=vec[l];
		}
		return ;
	}
	int mid=(l+r)>>1;
	flow.init(p.size()+2);
	f(i,1,n+1) mark[i]=0;
	f(i,0,p.size()) mark[p[i]]=i+1;
	f(i,1,m+1){
		if(mark[s[i]] && mark[t[i]]){
			flow.addEdge(mark[t[i]],mark[s[i]],inf);
		}
	}
	f(i,0,p.size()){
		if(a[p[i]]<=vec[mid]){
			flow.addEdge(0,i+1,1);
		}
		else{
			flow.addEdge(i+1,p.size()+1,1);
		}
	}
	flow.maxFlow(0,p.size()+1);
	vector<int> lc,rc;
	f(i,0,p.size()){
		if(flow.dist[i+1]!=inf){
				lc.pb(p[i]);
		}
		else{
			rc.pb(p[i]);
		}
	}
	solve(l,mid,lc);
	solve(mid+1,r,rc);
}
int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	f(i,1,n+1) cin>>a[i],vec.pb(a[i]);
	f(i,1,m+1){
		cin>>s[i]>>t[i];
	}
	sort(all(vec));
	vec.resize(unique(all(vec))-vec.begin());
	vector<int> p(n);
	iota(all(p),1);
	solve(0,vec.size()-1,p);
	f(i,1,n+1) cout<<ans[i]<<" ";
}