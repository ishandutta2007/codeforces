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

const int N=20;

int n,t,dor,ans,mark[N],m[N][N],LB[(1<<N)],dp[(1<<N)];
int F[N][(1<<N)];
string a,b;
vector<int> g[N];

void make(){
	f(mask,1,(1<<N))
		f(i,0,N)
			if(is_bit(mask,i)){
				LB[mask]=i;
				break;
			}
}
void clear(){
	ans=N;
	fill(mark,mark+N,0);
	f(i,0,N) g[i].clear();
	f(i,0,N) f(j,0,N) m[i][j]=0;
	f(i,0,n)
		if(a[i]!=b[i]){
			g[a[i]-'a'].pb(b[i]-'a'),g[b[i]-'a'].pb(a[i]-'a');
			m[a[i]-'a'][b[i]-'a']=1;
		}
}
void dfs(int x){
	mark[x]=1;
	f(i,0,g[x].size())
		if(!mark[g[x][i]])
			dfs(g[x][i]);
}
void solve(int x,int mask){
	if(is_bit(mask,x)) return ;
	F[x][mask]=(F[x][mask-(1<<LB[mask])] || m[x][LB[mask]]);
}
void calc(int mask){
	dp[mask]=N*N;
	f(i,0,N)
		if(is_bit(mask,i))
			minm(dp[mask],dp[mask-(1<<i)]+F[i][mask-(1<<i)]);
}
void do_it(){
	f(i,0,N)
		f(mask,1,(1<<N))
			solve(i,mask);
	f(i,1,(1<<N))
		calc(i);
}
void solve(){
	clear();
	f(i,0,N)
		if(!mark[i])
			dfs(i),ans--;
	do_it();
	cout<<ans+dp[(1<<N)-1]<<'\n';
}

int main(){
	make();
	cin>>t;
	while(t--){
		cin>>n;
		cin>>a>>b;
		solve();		
	}
}