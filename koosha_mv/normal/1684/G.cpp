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
#define int ll

typedef int fType;
 
struct edge
{
	int from, to;
	fType cap, flow;
	edge(int from, int to, fType cap, fType flow = 0) : from(from), to(to), cap(cap), flow(flow) {}	
};
 
struct PushRelabel
{
	int N;
	vector<edge> edges;
	vector<vector<int> > G;
	vector<int> h, inQ, count;
	vector<fType> excess;
	queue<int> Q;
	PushRelabel(int N) : N(N), count(N<<1), G(N), h(N), inQ(N), excess(N) {}
 
	void addedge(int from, int to, int cap) {
		G[from].push_back(edges.size());
		edges.push_back(edge(from, to, cap));
		G[to].push_back(edges.size());
		edges.push_back(edge(to, from, 0));
	}
 
	void enQueue(int u) {
		if(!inQ[u] && excess[u] > 0) Q.push(u), inQ[u] = true;
	}
 
	void Push(int edgeIdx) {
		edge & e = edges[edgeIdx];
		int toPush = min<fType>(e.cap - e.flow, excess[e.from]);
		if(toPush > 0 && h[e.from] > h[e.to]) {
			e.flow += toPush;
			excess[e.to] += toPush;
			excess[e.from] -= toPush;
			edges[edgeIdx^1].flow -= toPush;
			enQueue(e.to);
		}
	}
 
	void Relabel(int u) {
		count[h[u]] -= 1; h[u] = 2*N-2;
		for (int i = 0; i < G[u].size(); ++i) {
			edge & e = edges[G[u][i]];
			if(e.cap > e.flow) h[u] = min(h[u], h[e.to]);
		}
		count[++h[u]] += 1;
	}
 
	void gapRelabel(int height) {
		for (int u = 0; u < N; ++u) if(h[u] >= height && h[u] < N) {
			count[h[u]] -= 1;
			count[h[u] = N] += 1;
			enQueue(u);
		}
	}
 
	void Discharge(int u) {
		for (int i = 0; excess[u] > 0 && i < G[u].size(); ++i) {
			Push(G[u][i]);
		}
		if(excess[u] > 0) {
			if(h[u] < N && count[h[u]] < 2) gapRelabel(h[u]);
			else Relabel(u);
		}
		else if(!Q.empty()) { // dequeue
			Q.pop();
			inQ[u] = false;
		}
	}
 
	fType getflow(int src, int snk) {
		h[src] = N; inQ[src] = inQ[snk] = true;
		count[0] = N - (count[N] = 1);
		for (int i = 0; i < G[src].size(); ++i) {
			excess[src] += edges[G[src][i]].cap;
			Push(G[src][i]);
		}
		while (!Q.empty()) {
			Discharge(Q.front());
		}
		return excess[snk];
	}
};

const int N=3030;

int n,m,a[N];
vector<pair<int,int>> ans;

int32_t main(){
	ios:: sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin>>n>>m;
	f(i,1,n+1) cin>>a[i];
	sort(a+1,a+n+1);
	int p=1;
	while(p<=n && 3ll*a[p]<=m) p++;

	PushRelabel Flow(n+2);
	f(i,1,p) Flow.addedge(0,i,1);
	f(i,p,n+1) Flow.addedge(i,n+1,1);
	f(i,1,p){
		f(j,p,n+1){
			if(a[j]%a[i]==0 && a[i]+a[j]+a[j]<=m){
				Flow.addedge(i,j,1);
			}
		}
	}
	//eror(Flow.getflow(0,n+1));
	if(Flow.getflow(0,n+1)<n-p+1){
		return cout<<-1,0;
	}
	int cnt=0;
	f(i,1,p){
		if(Flow.edges[cnt<<1].flow==0) ans.pb({2*a[i],3*a[i]});
		cnt++;
	}
	f(i,p,n+1) cnt++;
	f(i,1,p){
		f(j,p,n+1){
			if(a[j]%a[i]==0 && a[i]+a[j]+a[j]<=m){
				if(Flow.edges[cnt<<1].flow==1) ans.pb({a[i]+a[j],a[i]+a[j]+a[j]});
				cnt++;
			}
		}
	}
	cout<<ans.size()<<endl;
	for(auto p : ans) cout<<p.F<<" "<<p.S<<endl;
}