#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define is_bit(x,y) (x%(1<<(y+1))>=(1<<y))
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod
#define lst(x) x[x.size()-1]
#define sz(x) int(x.size())
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2e5+99;

int n,m,t,x,y,ans,par[N],mark[N];
vector<int> v[N];

int Get_par(int u){
	if(u>n || u<1) return N;
	if(par[u]<0) return u;
	return (par[u]=Get_par(par[u]));
}
void merge(int x,int y){
	if(par[mark[x]]<par[mark[y]]){
	//	ops(4);
		f(i,0,v[mark[y]].size())
			ans+=(Get_par(v[mark[y]][i]+1)==mark[x])+(Get_par(v[mark[y]][i]-1)==mark[x]);
		f(i,0,v[mark[y]].size())
			v[mark[x]].pb(v[mark[y]][i]);
		par[mark[x]]+=par[mark[y]];
		par[mark[y]]=mark[x];
	}
	else{
	//	ops(3);
		f(i,0,v[mark[x]].size())
			ans+=(Get_par(v[mark[x]][i]+1)==mark[y])+(Get_par(v[mark[x]][i]-1)==mark[y]);
		f(i,0,v[mark[x]].size())
			v[mark[y]].pb(v[mark[x]][i]);
		par[mark[y]]+=par[mark[x]];
		par[mark[x]]=mark[y];
		mark[x]=mark[y];
	}
	//ops(2);
}
int main(){
	cin>>n>>m;
	f(i,1,n+1){
		gett(x);
		v[x].pb(i);
	}
	f(i,1,m+1){
		sort(v[i].begin(),v[i].end());
		mark[i]=v[i][0];
		par[v[i][0]]=-1*sz(v[i]);
		f(j,1,v[i].size()) par[v[i][j]]=v[i][0],ans+=(v[i][j]==v[i][j-1]+1);
	}
	f(i,1,n+1) v[i].clear();
	f(i,1,n+1)
		v[Get_par(i)].pb(i);
	cout<<n-1-ans<<endl;
	f(i,1,m){
		Gett(x,y);
		merge(x,y);
		cout<<n-1-ans<<'\n';
	}
}