#include<bits/stdc++.h>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;++i)
#define fd(i,a,b)for(int i=b,_e=a;i>=_e;--i)
#define P pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e5+5;
int n,q,ans,x,y,l,d[N],rt,rt1;
vector<P>e[N];
bool cmp(P a,P b){return a.fi>b.fi||a.fi==b.fi&&a.se<b.se;}
struct tree{
	int d[N],ld[N],mx[N],la[N],be[N],bs;
	int f[N][17],su[N],ds;
	P b[N];
	void dfs(int x){
		fo(i,1,16){
			if(!f[x][i-1])break;
			f[x][i]=f[f[x][i-1]][i-1];
		}
		for(P i:e[x])if(i.fi!=f[x][0])
			f[i.fi][0]=x,d[i.fi]=d[x]+i.se,dfs(i.fi),(ld[i.fi]+i.se>ld[x]?ld[x]=ld[i.fi]+i.se,mx[x]=i.fi:0);
	}
	void dfs2(int x,int st){
		ld[x]=st;
		if(!mx[x]){
			la[st]=x;
			b[ds++]=P(d[x]-d[f[st][0]],st);
			return;
		}
		dfs2(mx[x],st);
		for(P i:e[x])if(i.fi!=f[x][0]&&i.fi!=mx[x])dfs2(i.fi,i.fi);
	}
	void init(int rt){
		dfs(rt);
		dfs2(rt,rt);
		sort(b,b+ds,cmp);
		fo(i,0,ds-1)su[i]=(i?su[i-1]:0)+b[i].fi,be[b[i].se]=i;
		fo(i,1,n)be[i]=be[ld[i]];
	}
	int qry(){
		if(ds/2+1<=y)return su[ds-1];
		y=(y-1)*2;
		if(be[x]<=y)return su[y];
		int z=x;
		fd(i,0,16)if(be[f[z][i]]>y)z=f[z][i];
		z=f[z][0];
		return max(su[y-1],su[y]-d[la[ld[z]]]+d[z])+d[la[ld[x]]]-d[z];
	}
}a[2];
void dfs(int x,int ff){
	for(P i:e[x])if(i.fi!=ff)d[i.fi]=d[x]+i.se,dfs(i.fi,x);
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>q;
	fo(i,2,n)cin>>x>>y>>l,e[x].pb(P(y,l)),e[y].pb(P(x,l));
	dfs(1,0);
	fo(i,1,n)if(d[i]>d[rt])rt=i;
	a[0].init(rt);
	fo(i,1,n)if(a[0].d[i]>a[0].d[rt1])rt1=i;
	a[1].init(rt1);
	for(;q--;){
		cin>>x>>y;
		x=(x+ans-1)%n+1;y=(y+ans-1)%n+1;
		ans=a[a[1].d[x]>a[0].d[x]].qry();
		cout<<ans<<endl;
	}
}