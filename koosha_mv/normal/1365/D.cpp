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
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=55,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};

int n,ng,m,t,x,y,mark[N][N];
char mp[N][N];

bool ini(int x,int y){
	if(x<0 || y<0 || x>n-1 || y>m-1) return 0;
	return 1;
}
void dfs(int x,int y){
	mark[x][y]=1;
	f(i,0,4){
		int u=x+dx[i],v=y+dy[i];
		if(ini(u,v) && mp[u][v]!='#' && !mark[u][v])
			dfs(u,v);
	}
}
void solve(){
	ng=0;
	cin>>n>>m;
	f(i,0,n)
		f(j,0,m)
			mark[i][j]=0;
	f(i,0,n)
		f(j,0,m)
			cin>>mp[i][j];
	f(i,0,n)
		f(j,0,m)
			if(mp[i][j]=='B'){
				f(k,0,4){
					x=i+dx[k],y=j+dy[k];
					if(ini(x,y) && mp[x][y]=='G'){
						cout<<"No"<<endl;
						return ;
					}
				}
			}
	f(i,0,n)
		f(j,0,m)
			if(mp[i][j]=='.'){
				f(k,0,4){
					x=i+dx[k],y=j+dy[k];
					if(ini(x,y) && mp[x][y]=='B')
						mp[i][j]='#';
				}
			}
	if(mp[n-1][m-1]!='#') dfs(n-1,m-1);
	f(i,0,n)
		f(j,0,m)
			if(mp[i][j]=='G' && !mark[i][j]){
					cout<<"No"<<endl;
					return ;
				}
	cout<<"Yes"<<endl;
}

int main(){
	cin>>t;
	while(t--)
		solve();
}