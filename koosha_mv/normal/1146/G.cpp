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
#define int ll

struct DinicCapacityScaling {
	struct Edge {
		int to;
		int cap;
		
		Edge () : to(), cap() {}
		Edge (int _to, int _cap) : to(_to), cap(_cap) {}
	};
	int n;
	int D;
	vector< Edge > E;
	vector< vector<int> > G;
	vector< int > idx, dis, Q;

	DinicCapacityScaling(int _n) : n(_n) {
		G.resize(_n);
		idx.resize(_n);
		dis.resize(_n);
		Q.resize(_n);
	}
	void Addedge(int u, int v, int cap){
		G[u].push_back((int) E.size());
		E.push_back({v, cap});

		G[v].push_back((int) E.size());
		E.push_back({u, 0});
	}
	bool BFS(int src, int snk){
		fill(dis.begin(), dis.end(), -1);
		
		dis[src] = 0;
		int L = 0, R = 1;
		Q[0] = src;
		
		int fr;
		while(L < R){
			fr = Q[L ++];
			for(auto id : G[fr]){
				if(E[id].cap >= D && dis[ E[id].to ] == -1){
					dis[ E[id].to ] = dis[fr] + 1;
					Q[R ++] = E[id].to;
				}
			}
		}
		return dis[snk] != -1;
	}

	int DFS(int u, int snk, int flow){
		if(u == snk || flow == 0) return flow;

		int res = 0, cur;
		for(auto &id = idx[u]; id < (int) G[u].size(); id ++){
			Edge &ed = E[ G[u][id] ];
			
			if(dis[ ed.to ] != dis[u] + 1 || ed.cap < D) continue;
			
			cur = DFS(ed.to, snk, min(flow, ed.cap));
			flow -= cur; res += cur;
			
			ed.cap -= cur;
			E[ G[u][id] ^ 1 ].cap += cur;
			if(flow == 0) break;
		}
		return res;
	}

	int MaxFlow(int src, int snk){
		int res = 0;
		D = numeric_limits<int>::max();
		while(D){
			while( BFS(src, snk) ){
				fill(idx.begin(), idx.end(), 0);
				res += DFS(src, snk, numeric_limits<int>::max());
			}
			D /= 2;
		}
		return res;
	}
	int Mincut(int src, int snk){
		return MaxFlow(src, snk);
	}
};
using Dinic = DinicCapacityScaling;

const int N=1e6+99,inf=1e9;

int n,h,m;

main(){
	cin>>n>>h>>m;
	Dinic Flow(n*h+m+2);
	int src=n*h+m,snk=n*h+m+1;
	f(i,0,n){
		f(j,0,h){
			Flow.Addedge(i*h+j,snk,2*j+1);
			if(j+1<h) Flow.Addedge(i*h+j,i*h+j+1,inf); 
		}
	}
	f(i,0,m){
		int l,r,x,cost;
		cin>>l>>r>>x>>cost; l--;
		
		if(x==h) continue ;
		
		Flow.Addedge(src,n*h+i,cost);
		f(j,l,r){
			Flow.Addedge(n*h+i,j*h+x,inf);
		}
	}
	cout<<n*h*h-Flow.Mincut(src,snk);
}