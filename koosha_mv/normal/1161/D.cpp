#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(int i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(int i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=2002,mod=998244353;

int n,res,ans,mark[N],col[N];
string s;
vector<pair<int,int> > g[N];

void do_it(){
	f(i,1,2*n+1) g[i].clear();
	f(i,1,n+1){
		mark[i]=mark[i+n]=0,col[i]=col[i+n]=-1;
		if(n%2==0 || i!=n/2+1) 
			g[i].pb(mp(n-i+1,0));
		if(s[i]!='?'){
			g[i].pb(mp(i+n,s[i]-'0'));
			g[i+n].pb(mp(i,s[i]-'0'));
		}
	}
}
void dfs(int x,int c){
	if(col[x]>-1 && col[x]!=c) res=0;
	mark[x]=1,col[x]=c;
	f(i,0,g[x].size())
		if(mark[g[x][i].F] && col[g[x][i].F]!=(c+g[x][i].S)%2)
			res=0;
	f(i,0,g[x].size())
		if(!mark[g[x][i].F])
			dfs(g[x][i].F,(c+g[x][i].S)%2);
}
void solve(int x){
	res=1;
	do_it();
	f(i,x+n,2*n+1)
		g[i].pb(mp(2*n-(i-x-n),0));
	col[1]=1,col[x+n]=1;
	f(i,1,x)
		col[i+n]=0;
	f(i,n+1,n*2+1)
		if(!mark[i]){
			if(col[i]==-1) col[i]=0;
			dfs(i,col[i]);
			if(i>x+n) res=res*2ll%mod;
		}
	f(i,1,n+1)
		if(!mark[i]){
			if(col[i]==-1) col[i]=0;
			dfs(i,col[i]);
			res=res*2ll%mod;
		}
	ans=(ans+res)%mod;
}
int main(){
	cin>>s;
	n=s.size();
	s=' '+s;
	f(i,2,n+1)
		solve(i);
	cout<<ans;
}