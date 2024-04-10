#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define ll long long
#define P pair<int,int>
#define F first
#define S second
#define pb push_back
using namespace std;
const int N=1e5+5;
int n,nn,x,y,v,q,mx,ds,ans;
int df[N],w[N],ri[N],an[N],t[N];
vector<P>e[N],qu[N];
ll dis[N],di2[N],l;
void dfs(int x,int ff){
	for(P i:e[x])if(i.F!=ff)dis[i.F]=dis[x]+i.S,dfs(i.F,x);
}
void dfs2(int x,int ff){
	qu[ds].pb(P(x,-1));
	df[++ds]=x;
	for(P i:e[x])if(i.F!=ff)dfs2(i.F,x);
	qu[ds].pb(P(x,1));
}
void ch(int x){
	for(;x<=nn;x+=x&-x)++t[x];
}
int qry(int x){
	int s=0;
	for(;x;x&=x-1)s+=t[x];
	return s;
}
int main(){
	cin>>n;
	fo(i,2,n)scanf("%d%d%d",&x,&y,&v),e[x].pb(P(y,v)),e[y].pb(P(x,v));
	dfs(1,0);
	fo(i,1,n)if(dis[i]>dis[mx])mx=i;
	dis[mx]=0;
	dfs(mx,0);
	fo(i,1,n){
		di2[i]=dis[i];
		if(dis[i]>dis[mx])mx=i;
	}
	dis[mx]=0;
	dfs(mx,0);
	fo(i,1,n)di2[i]=max(di2[i],dis[i]);
	mx=1;
	fo(i,2,n)if(di2[i]<di2[mx])mx=i;
	dfs2(mx,0);
	fo(i,1,n)dis[i]=di2[i];
	sort(dis+1,dis+n+1);
	nn=unique(dis+1,dis+n+1)-dis-1;
	fo(i,1,n)w[i]=lower_bound(dis+1,dis+nn+1,di2[i])-dis;
	for(cin>>q;q--;){
		cin>>l;
		memset(an,0,(n+1)*4);
		memset(t,0,(nn+1)*4);
		ans=0;
		int j=1;
		fo(i,1,nn){
			for(;j<=nn&&dis[j]-dis[i]<=l;)++j;
			ri[i]=j-1;
		}
		fo(i,1,n){
			x=df[i];
			ch(w[x]);
			for(P k:qu[i])
				an[k.F]+=k.S*(qry(ri[w[k.F]])-qry(w[k.F]-1));
		}
		fo(i,1,n)ans=max(ans,an[i]);
		cout<<ans<<endl;
	}
}