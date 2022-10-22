#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define get(x) scanf("%I64d",&x);
#define Gett(x,y) scanf("%d%d",&x,&y);
#define gett(x) scanf("%d",&x);
#define f(i,a,b) for(int i=a;i<b;i++)
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define S second
#define F first
#define mp make_pair
const int N=3e6+99;
int n,x,y,cnt=-1,as[N],at[N],ad[N],centroid[N],sub[N],k=20,p,mark1[N],u,mark2[N],ans,w,mark3[N];
vector<int> g[N],quer[N];
map < pair < int , int> ,int> maap;
void solve_queries_ofline(){
	f(i,0,n){
		u=sub[ad[i]];
		p=0;
		if(u<=n/2){
			f_(j,k-1,0){
				if(u>=(1<<j)){
					u-=(1<<j);
					p+=(1<<j);
					mark1[p]++;
				}
			}
		}
		f(j,0,quer[i].size()){
			p=(1<<k);
			u=(1<<k)-quer[i][j];
			ans=0;
			f_(l,k-1,0){
				if(u>=(1<<l)){
					u-=(1<<l);
					p-=(1<<l);
					ans+=mark1[p];
				}
			}
			maap[make_pair(i,quer[i][j])]=ans;
		}
	}
}
void dfs_data(int x,int par){
	sub[x]=1;
	as[x]=++cnt;
	ad[cnt]=x;
	f(i,0,g[x].size())
		if(g[x][i]!=par){
			dfs_data(g[x][i],x);
			sub[x]+=sub[g[x][i]];
		}
	at[x]=cnt;
}
void add_query(int x,int par){
	f(i,0,g[x].size()){
		if(g[x][i]!=par && sub[g[x][i]]>n/2){
			quer[at[x]].pb(sub[g[x][i]]-n/2);
			quer[as[x]].pb(sub[g[x][i]]-n/2);
		}
	}
}
void ad_query(int x,int par){
	quer[n-1].pb(n-sub[x]-n/2);
	quer[at[x]].pb(n-sub[x]-n/2);
	quer[as[x]-1].pb(n-sub[x]-n/2);
}
void dfs_query(int x,int par){
	f(i,0,g[x].size())
		if(g[x][i]!=par)
			dfs_query(g[x][i],x);
	if(sub[x]>n/2)
		add_query(x,par);
	else
		ad_query(x,par);
}
void dfs_solve(int x,int par){
	p=(1<<k);
	u=(1<<k)-(n-sub[x]-n/2);
	w=0;
	f_(i,k-1,0){
		if(u>=(1<<i)){
			u-=(1<<i);
			p-=(1<<i);
			w+=mark3[p];
		}
	}
	p=0;
	u=sub[x];
	if(u<=n/2){
		f_(i,k-1,0){
			if(u>=(1<<i)){
				u-=(1<<i);
				p+=(1<<i);
				mark3[p]++;
			}
		}
	}
	if(sub[x]<n/2+(n%2)){
		int y=(1<<k)-(n-sub[x]-n/2);
		p=(1<<k);
		f_(i,k-1,0){
			if(y>=(1<<i)){
				y-=(1<<i);
				p-=(1<<i);
				centroid[x]+=mark2[p];
			}
		}
		if(maap[mp(n-1,(n-sub[x]-n/2))]-(maap[mp(at[x],(n-sub[x]-n/2))]-maap[mp(as[x]-1,(n-sub[x]-n/2))])-w)
			centroid[x]=1;
	}
	else{
		centroid[x]=1;
		f(i,0,g[x].size()){
			if(sub[g[x][i]]<sub[x] && sub[g[x][i]]>n/2){
				if(maap[mp(at[x],sub[g[x][i]]-n/2)]==maap[mp(as[x],sub[g[x][i]]-n/2)])
					centroid[x]=0;
			}
		}
	}
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			y=n-sub[g[x][i]];
			p=0;
			if(y<=n/2){
				f_(j,k-1,0){
					if(y>=(1<<j)){
						y-=(1<<j);
						p+=(1<<j);
						mark2[p]++;
					}
				}
			}
			dfs_solve(g[x][i],x);
			y=n-sub[g[x][i]];
			p=0;
			if(y<=n/2){
				f_(j,k-1,0){
					if(y>=(1<<j)){
						y-=(1<<j);
						p+=(1<<j);
						mark2[p]--;
					}
				}
			}
		}
	}
	p=0;
	u=sub[x];
	if(u<=n/2){
		f_(i,k-1,0){
			if(u>=(1<<i)){
				u-=(1<<i);
				p+=(1<<i);
				mark3[p]--;
			}
		}
	}
}
int main(){
	cin>>n;
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs_data(1,0);
	dfs_query(1,0);
	solve_queries_ofline();
	dfs_solve(1,0);
	f(i,1,n+1)
		cout<<(centroid[i]>0)<<" ";
}