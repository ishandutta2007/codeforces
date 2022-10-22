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

const int N=2e5+9,Q=120,inf=1e8+9;

int n,m,u,v,c,T,s[N],t[N],dp[N],sub[N],par[N],dist[N];
pair<int,int> p,a[N],bcke[N],edge[N];
vector<int> ans,g[N];

void clear(){
	ans.clear();
	f(i,1,n+1) g[i].clear(),dp[i]=0;
}
int solve(int x){
	f(i,1,n+1)
		a[i].F=dist[i],a[i].S=i;
	sort(a+1,a+1+n);
	f(i,1,n+1)
		if((sub[a[i].S]==1 && dp[bcke[a[i].S].S]) || (i==1))
			dp[a[i].S]=1;
	f(i,1,n+1)
		if(dp[i])
			ans.pb(i);
	return 1;
}
bool check(int x,int fa){
	bool ans=1;
	sub[x]=0,bcke[x].F=N;
	s[x]=c++,dist[x]=fa;
	f(i,0,g[x].size())
		if(s[g[x][i]] && !t[g[x][i]]){
			p=mp(dist[g[x][i]],g[x][i]);
			if(p<bcke[x])
				bcke[x]=p;
			sub[x]++,sub[g[x][i]]--;
		}	
	f(i,0,g[x].size())
		if(!s[g[x][i]]){
			par[g[x][i]]=x,check(g[x][i],fa+1);
			if(bcke[g[x][i]]<bcke[x]) bcke[x]=bcke[g[x][i]];
			sub[x]+=sub[g[x][i]];
		}
	t[x]=c-1;
	if(fa==0){
		par[x]=0;
		f(i,0,m)
			if((s[edge[i].F]<s[edge[i].S] || t[edge[i].S]<s[edge[i].F]) && (par[edge[i].S]!=edge[i].F))
				ans=0;
	}
	return ans;
}
int mv(){
	cin>>n>>m;
	clear();
	f(i,0,m){
		Gett(u,v);
		edge[i].F=u,edge[i].S=v;
		g[u].pb(v);
	}
	f(i,0,Q){
		fill(s,s+n+1,0);
		fill(t,t+n+1,0);
		u=((1ll*rand()*1ll*rand()+rand())%n)+1,c=1;
		if(check(u,0)){ 
			solve(u);
			break;
		}
	}
	if(ans.size()<n/5+(n%5>0)) cout<<-1<<'\n';
	else print(ans,ans.size());
	return 0;
}

int main(){
	srand(time(NULL));
	for(scanf("%d",&T);T--;)
		mv();
}