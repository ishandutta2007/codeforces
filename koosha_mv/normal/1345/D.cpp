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
#define bit(x) (1ll<<(x*1ll))
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=1002,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int n,m,t,ans,r[N],c[N],mark[N][N];
char a[N][N];

bool ini(int x,int y){
	if(x<0 || y<0 || x>=n || y>=m) return 0;
	return 1;
}
void dfs(int x,int y){
	mark[x][y]=1;
	f(i,0,4){
		int u=x+dx[i],v=y+dy[i];
		if(ini(u,v) && mark[u][v]==0 && a[u][v]=='#')
			dfs(u,v);
	}
}
void kill(){
	cout<<-1;
	exit(0);
}
void solve(string v){
	int res=0;
	f(i,0,v.size())
		if(v[i]=='#' && (i==0 || v[i-1]=='.')) res++;
	if(res>1) kill();
}
void check(){
	f(i,0,n){
		string s="";
		f(j,0,m) s+=a[i][j];
		solve(s);
	}
	f(j,0,m){
		string s="";
		f(i,0,n) s+=a[i][j];
		solve(s);
	}
}

int main(){
	cin>>n>>m;
	f(i,0,n)
		f(j,0,m){
			cin>>a[i][j];
			if(a[i][j]=='#') r[i]=1,c[j]=1,t++;
		}
	if(t==n*m) return cout<<1,0;
	f(i,0,n) if(r[i]==0) ans=1;
	if(ans==0){
		f(j,0,m){
			bool p=1;
			f(i,0,n)
				if(a[i][j]=='#')
					p=0;
			if(p) kill();
		}
	}
	ans=0;
	f(i,0,m) if(c[i]==0) ans=1;
	if(ans==0){
		f(i,0,n){
			bool p=1;
			f(j,0,m)
				if(a[i][j]=='#')
					p=0;
			if(p) kill();
		}
	}
	check();
	ans=0;
	f(i,0,n)
		f(j,0,m)
			if(mark[i][j]==0 && a[i][j]=='#')
				dfs(i,j),ans++;
	cout<<ans;
}