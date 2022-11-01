#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define ll long long
#define P pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e5+5,mo=1e9+7;
int t,n,x,y;
int fa[N];
int tf[N],f[N],g[N];
vector<int>e[N];
void dfs(int x){
	f[x]=1;
	int su=0;
	for(int i:e[x])if(i!=fa[x]){
		fa[i]=x;
		dfs(i);
		f[x]=max(f[x],g[i]+1);
		++su;
	}
	for(int i:e[x])if(i!=fa[x])
		g[x]=max(g[x],su-1+max(f[i],g[i]));
}
void dfs2(int x){
	int su=0;
	int cf=0,belf=0,cg=0,belg=0;
	f[x]=g[x]=0;
	for(int i:e[x]){
		++su;
		if(g[i]+1>f[x]){
			cf=f[x];
			f[x]=g[i]+1;
			belf=i;
		}else
		if(g[i]+1>cf)cf=g[i]+1;
	}
	for(int i:e[x]){
		int v=su-1+max(f[i],g[i]);
		if(v>g[x]){
			cg=g[x];
			g[x]=v;
			belg=i;
		}else
		if(v>cg)cg=v;
	}
	if(x==3){
		int kk=0;
	}
	int lasf=f[x],lasg=g[x];
//	tf[x]=max(f[x],g[x]);
	tf[x]=f[x];
	for(int i:e[x])if(i!=fa[x]){
		if(x==3&&i==4){
			int kk=0;
		}
		if(x==4&&i==5){
			int kk=0;
		}
		if(su==1){
			f[x]=1;
			g[x]=0;
		}else{
			f[x]=belf==i?cf:lasf;
			g[x]=belg==i?cg:lasg;
			--g[x];
		}
		dfs2(i);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	fo(i,2,n)cin>>x>>y,e[x].pb(y),e[y].pb(x);
	dfs(1);
	dfs2(1);
	int ans=0;
	fo(i,1,n)ans=max(ans,tf[i]);
	cout<<ans<<endl;
}