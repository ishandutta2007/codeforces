#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,son[100005],sz[100005],tp[100005],dep[100005],fa[100005];
vector<pair<int,int> > v[100005];
ll w[100005],tot,res;
pair<int,int> d[100005];

void dfs0(int x,int f){
	sz[x]++;
	fa[x]=f;
	for(auto [i,j]:v[x])if(i!=f){
		dep[i]=dep[x]+1;
		w[i]=w[x]+j;
		dfs0(i,x);
		sz[x]+=sz[i];
		if(sz[i]>=sz[son[x]])son[x]=i;
	}
}
void dfs1(int x,int fa,int t){
	tp[x]=t;
	if(son[x])dfs1(son[x],x,t);
	for(auto [i,j]:v[x])if(i!=fa&&i!=son[x]){
		dfs1(i,x,i);
	}
}
int lca(int x,int y){
	while(tp[x]!=tp[y]){
		if(dep[tp[x]]>dep[tp[y]])x=fa[tp[x]];
		else y=fa[tp[y]];
	}
	return (dep[x]<dep[y])?x:y;
}
ll dis(int x,int y){
	return w[x]+w[y]-2*w[lca(x,y)];
}

pair<int,int> hb(pair<int,int> x,pair<int,int> y){
	int i,j,f[5],r1,r2;
	ll sb=-1,t1;
	auto [a,b]=x; auto [c,d]=y;
	f[1]=a; f[2]=b; f[3]=c; f[4]=d;
	for(i=1;i<=4;i++){
		for(j=i+1;j<=4;j++){
			t1=dis(f[i],f[j]);
			if(t1>sb){
				sb=t1;r1=f[i];r2=f[j];
			}
		}
	}
	return {r1,r2};
}

void dfs2(int x,int fa){
	d[x]={x,x};
	for(auto [i,j]:v[x]){
		if(i==fa)continue;
		dfs2(i,x);
		d[x]=hb(d[x],d[i]);
	}
	auto [i,j]=d[x];
}

void dfs3(int x,int fa,pair<int,int> lst){
	if(x!=1){
		lst=hb(lst,{x,x});
	}
	int i,j,k,n=v[x].size();
	ll t1,t2;
	vector<pair<int,int> > dl(n+5),dr(n+5);
	pair<int,int> sb;
	m=0;
	for(auto [i,j]:v[x]){
		if(i==fa)continue;
		m++;
		dl[m]=dr[m]=d[i];
	}
	dl[0]=dr[m+1]={x,x};
	for(i=1;i<=m;i++){
		dl[i]=hb(dl[i],dl[i-1]);
		dr[m+1-i]=hb(dr[m+1-i],dr[m+2-i]);
	}
	k=0;
	for(auto [i,j]:v[x]){
		if(i==fa)continue;
		k++;
		sb=hb(dl[k-1],dr[k+1]);
		sb=hb(sb,lst);
		auto [a,b]=sb; auto [c,e]=d[i];
		res=max(res,dis(a,b)+dis(c,e)+j+j);
		dfs3(i,x,sb);
	}
}
ll nmsl[100005];
void dfs4(int x,int fa){
	for(auto [i,j]:v[x]){
		if(i==fa)continue;
		dfs4(i,x);
		nmsl[x]=max(nmsl[x],nmsl[i]+j);
	}
}
void dfs5(int x,int fa,ll lst){
	int i,j,k,n=v[x].size();
	ll tmp=0,sb;
	vector<ll> dl(n+5),dr(n+5),NMSL={lst};
	m=0;
	for(auto [i,j]:v[x]){
		if(i==fa)continue;
		m++;
		dl[m]=dr[m]=nmsl[i]+j;
		NMSL.push_back(nmsl[i]+j);
	}
	sort(NMSL.begin(),NMSL.end());
	for(i=1;i<=4;i++){
		if(NMSL.empty())break;
		tmp+=NMSL.back();NMSL.pop_back();
	}
	res=max(res,tmp);
	for(i=1;i<=m;i++){
		dl[i]=max(dl[i],dl[i-1]);
		dr[m+1-i]=max(dr[m+1-i],dr[m+2-i]);
	}
	k=0;
	for(auto [i,j]:v[x]){
		if(i==fa)continue;
		k++;sb=max({dl[k-1],dr[k+1],lst});
		dfs5(i,x,sb+j);
	}
}
int main() {
    ios::sync_with_stdio(0);
    cin>>n;
    for(i=1;i<n;i++){
    	cin>>j>>k>>t;
    	v[j].push_back({k,t});
    	v[k].push_back({j,t});
    	tot+=t*2;
	}
	dfs0(1,1);dfs1(1,1,1);dfs2(1,0);dfs3(1,0,{1,1});dfs4(1,0);dfs5(1,0,0);
	cout<<tot-res;
}