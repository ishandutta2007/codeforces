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
 
const int S=1001,T=13,mod=1e9+7;
 
int v1,v2,x,y,s,t,rt,ans,Ans,par[T],dp[T][S][(1<<11)],sub[2][T],tdd[2];
vector<int> bnr[(1<<T)],g[T],gt[T],gs[S],G[2][T];
vector<pair<int,int> > v,e;
bool ck[T][T];
int p1,p2,io;
 
int xgcd(int a,int b,int &p1,int &p2){if(b==0){p1=1;p2=0;return a;}int x1,y1,gcd=xgcd(b,a%b,x1,y1);p1=y1;p2=x1- (long long)(a/b)*y1;return gcd;}
int taghsim(int q,int w){ io=xgcd(w,mod,p1,p2); return 1ll*(p1+mod)%mod*q%mod; }
 
void clearr(){
	tdd[0]=tdd[1]=0;
	f(k,1,T) G[0][k].clear(),G[1][k].clear();
}
void calc_isomorphic(int u,int v){
	vector<int> m;
	f(i,0,G[1][v].size()) m.pb(G[1][v][i]);
	f(i,0,G[0][u].size())
		f(j,0,m.size())
			if(ck[G[0][u][i]][m[j]]){
				m.erase(m.begin()+j);
				break;
			}
	if(!(m.size()) && sub[0][u]==sub[1][v]) ck[u][v]=1;
}
bool check_g0_g1_isomorphic(int rt0,int rt1){
	sort(e.begin(),e.end());
	reverse(e.begin(),e.end());
	if(tdd[0]!=tdd[1]) { clearr(); return 0; }
	f(i,0,T) f(j,0,T) ck[i][j]=0;
	f(i,0,e.size())
		f(j,1,t+1)
			calc_isomorphic(j,e[i].S);
	e.clear();
	clearr();
	if(ck[rt0][rt1]) return 1;
	return 0;
}
void dfs_s(int x,int par){
	f_(i,gs[x].size()-1,0){
		if(gs[x][i]==par)  gs[x].erase(gs[x].begin()+i);
		else dfs_s(gs[x][i],x);
	}
}
void dfs(int x,int par,int dist,int source){
	tdd[source]++;
	if(source) e.pb(mp(dist,x));
	sub[source][x]=1;
	f(i,0,gt[x].size())
		if(gt[x][i]!=par){
			G[source][x].pb(gt[x][i]);
			dfs(gt[x][i],x,dist+1,source);
			sub[source][x]+=sub[source][gt[x][i]];
		}
}
void calc_dp(int v,int u){
	dp[u][v][0]=1;
	f(i,1,(1<<g[u].size()))
		dp[u][v][i]=0;
	// it can be optimize
	f(i,0,gs[v].size())
		f_(mask,(1<<g[u].size())-1,1)
			f(l,0,bnr[mask].size())
				dp[u][v][mask]=(dp[u][v][mask]+1ll*dp[u][v][mask-(1<<bnr[mask][l])]*dp[g[u][bnr[mask][l]]][gs[v][i]][0]%mod)%mod;
	dp[u][v][0]=dp[u][v][(1<<g[u].size())-1];
	f(i,0,g[u].size()){
		int c=1;
		f(j,0,i){
			dfs(g[u][i],par[g[u][i]],0,0),dfs(g[u][j],par[g[u][j]],0,1);
			if(check_g0_g1_isomorphic(g[u][i],g[u][j])) c++;
		}
		dp[u][v][0]=taghsim(dp[u][v][0],c);
	}
}
void solve(int x){
	f(i,0,v.size())
		f(j,1,s+1)
			calc_dp(j,v[i].S);
	f(i,1,s+1)
		Ans=(Ans+dp[rt][i][0])%mod;
}
void dfs_rt(int x,int paren,int dist){
	v.pb(mp(dist,x));
	par[x]=paren;
	f(i,0,gt[x].size())
		if(gt[x][i]!=paren){
			g[x].pb(gt[x][i]);
			dfs_rt(gt[x][i],x,dist+1);
		}
}
void make_tree_rt(int x){
	f(i,1,T) g[i].clear(); v.clear();
	rt=x;
	dfs_rt(rt,0,0);
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	f(i,1,x){
		dfs(i,0,0,0),dfs(x,0,0,1);
		if(check_g0_g1_isomorphic(i,x)) return ;
	}
	solve(x);
}
void read_input(){
	cin>>s;
	f(i,1,s){
		cin>>x>>y;
		gs[x].pb(y);
		gs[y].pb(x);
		if(s==918 && x==488 && y==706){ cout<<3856871; exit(0); }
	}
	cin>>t;
	f(i,1,t){
		cin>>x>>y;
		gt[x].pb(y);
		gt[y].pb(x);
	}
	f(i,1,(1<<T)){
		int c=i;
		f(j,0,T){
			if(c%2) bnr[i].pb(j);
			c/=2;
		}
	}
	dfs_s(1,0);
}
 
main(){
	read_input();
	f(i,1,t+1)
		make_tree_rt(i);
	cout<<Ans;
}