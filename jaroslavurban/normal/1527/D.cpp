#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=200100;
int d[N],p[N],onp[N],dead[N];
vector<int>g[N];
int n,ld,rd,ci,nds;
int t=0,tin[N],tout[N];
ll res[N];

void clr(){
	memset(d,0,sizeof(*d)*(n+1));
	memset(p,0,sizeof(*p)*(n+1));
	memset(onp,0,sizeof(*onp)*(n+1));
	memset(dead,0,sizeof(*dead)*(n+1));
	for(int i=0;i<n;++i)g[i].clear();
	ld=0;rd=0;ci=0;nds=1;t=0;
	memset(tin,0,sizeof(*tin)*(n+1));
	memset(tout,0,sizeof(*tout)*(n+1));
	memset(res,0,sizeof(*res)*(n+1));
}

void dfs(int u,int p){
	tin[u]=t++;
	for(auto v:g[u])if(v!=p)dfs(v,u);
	tout[u]=t++;
}

bool ispar(int u,int v){return tin[u]<=tin[v]&&tout[u]>=tout[v];}

ll choose2(ll n){return n*(n-1)/2;}

int dep(int u,int par){
	p[u]=par;
	d[u]=1;
	int pp=0;
	for(auto v:g[u])if(v!=par){
		int r=dep(v,u);
		if(!u&&!ispar(v,1)){
			res[1]+=nds*ll(r);
			nds+=r;
		}
		else if(!u)pp=v;
		if(!u)res[0]+=choose2(r);
		if(u||!ispar(v,1))d[u]+=r;
	}
	if(!u){
		g[0].erase(remove(g[0].begin(),g[0].end(),pp),g[0].end());
		g[pp].erase(remove(g[pp].begin(),g[pp].end(),0),g[pp].end());
		return pp;
	}
	return d[u];
}

int ded(int u){
	int res=1;
	dead[u]=true;
	for(auto v:g[u])if(v!=p[u])res+=ded(v);
	return res;
}

int expath(int f,int t){
	int res=0;
//	cerr<<f<<" "<<t<<endl;
	while(f!=t){
		int pf=f;
		f=p[f];
		onp[f]=true;
		++res;
		for(auto v:g[f])if(v!=pf&&v!=p[f])res+=ded(v);
	}
	return res;
}


signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		cin>>n;clr();
		for(int i=0;i<n-1;++i){
			int u,v;cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(0,0);
		res[1]+=expath(1,dep(0,0))*ll(nds);
		ld=0,rd=1,ci=2;
		for(;!dead[ci]&&ci<n;++ci){
			if(onp[ci])continue;
			if(ispar(rd,ci)){
				int sm=expath(ci,rd);
				res[ci]=sm*ll(d[ld]);
				rd=ci;
			}else{
				int sm=expath(ci,ld);
				res[ci]=sm*ll(d[rd]);
				ld=ci;
			}
		}
		res[ci]+=d[ld]*ll(d[rd]);
		for(int i=0;i<=n;++i)cout<<res[i]<<" ";
		cout<<"\n";
	}
}