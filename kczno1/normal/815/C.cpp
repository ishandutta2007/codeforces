#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pb push_back
#define rep(i,l,r) for(int i=l;i<=r;++i)
void chmax(int &x,int y) { if(x<y)x=y; }
void chmin(int &x,int y) { if(x>y)x=y; }
const int N=5000+5;
int n,b;
int f1[N][N],f2[N][N],d[N];
int fa[N],sz[N];

void up(int x,int y)
{
	int szx=sz[x];
	int j=szx+1,mj=szx+sz[y];
	for(;j<=mj;++j)
	{
		int ans=b+1;
		for(int k=max(1,j-sz[y]);k<=szx;++k) chmin(ans,f1[x][k]+min(f1[y][j-k],f2[y][j-k]));
		f1[x][j]=ans;
		
		ans=b+1;
		for(int k=max(0,j-sz[y]);k<=szx;++k) chmin(ans,f2[x][k]+f2[y][j-k]);
		f2[x][j]=ans;
		
		if(f1[x][j]>b&&f2[x][j]>b)break;
	}
	sz[x]=j-1;
	
	for(int j=szx;j>0;--j)
	{
		for(int k=max(1,j-sz[y]);k<j;++k) chmin(f1[x][j],f1[x][k]+min(f1[y][j-k],f2[y][j-k]));
	}
	for(int j=szx;j>0;--j)
	{
		for(int k=max(0,j-sz[y]);k<j;++k) chmin(f2[x][j],f2[x][k]+f2[y][j-k]);
	}
}

int main()
{
	cin>>n>>b;
	cin>>f2[1][1]>>d[1];
	rep(i,2,n) cin>>f2[i][1]>>d[i]>>fa[i];

	rep(i,1,n)
	{
	  f1[i][1]=f2[i][1]-d[i];
	  if(f1[i][1]<=b)sz[i]=1;	
    }
    
    for(int i=n;i>1;--i) up(fa[i],i);
    printf("%d\n",sz[1]);
}