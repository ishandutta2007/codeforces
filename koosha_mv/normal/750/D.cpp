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
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define Add(x,y) x=(x+y)%mod;
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

bool mark[305][305][35][10];
bool vis[305][305];
int len[35];
int mx[]={0,1,1,1,0,-1,-1,-1};
int my[]={1,1,0,-1,-1,-1,0,1};
int n,ans;

void dfs(int x,int y,int rd,int d){
	if(rd>n||mark[x][y][rd][d]) return ;
	mark[x][y][rd][d]=1;
	int nx=x,ny=y;
	for(int i=0;i<len[rd];i++){
		nx+=mx[d];
		ny+=my[d];
		if(!vis[nx][ny])ans++,vis[nx][ny]=1;
	}
	dfs(nx,ny,rd+1,(d+1)%8);
	dfs(nx,ny,rd+1,(d+7)%8);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&len[i]);
	}
	dfs(150,150,1,0);
	printf("%d\n",ans);
	return 0;
}