#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <cstring>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
using namespace std;
const int N=1500;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n,n1,ans;
int a[N][N];
int b[N],b1[5];
bool z[5];
int s1,s2;
int T1,T2;
bool OK,GG;
int fx[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int q,int w,int I)
{
	if(q==T1&&w==T2){OK=1;return;}
	if(a[q][w]||!q||!w||q>n||w>m){GG=1;return;}
	if(I>n1)return;
	dfs(q+fx[b1[b[I]]][0],w+fx[b1[b[I]]][1],I+1);
}
void ss(int q)
{
	if(q>3)
	{
		OK=0;GG=0;
		dfs(s1,s2,1);
		if(OK)++ans;
	}
	fo(i,0,3)if(!z[i])
	{
		z[i]=1,b1[q]=i;
		ss(q+1);
		z[i]=0;
	}
}
int main()
{
	// freopen("!.in","r",stdin);
//	freopen(".out","w",stdout);
	int q,w;
	read(n),read(m);
	fo(i,1,n)
	{
		char ch=' ';
		for(;ch!='.'&&ch!='#'&&ch!='S'&&ch!='E';ch=getchar());
		fo(j,1,m)
		{
			if(ch=='S')
			{
				s1=i;s2=j;
			}else if(ch=='E')T1=i,T2=j;
			else if(ch=='#')a[i][j]=1;
			ch=getchar();
		}
	}
	char ch=' ';
	for(;ch<'0'||ch>'9';ch=getchar());
	n1=0;
	for(;ch<='9'&&ch>='0';ch=getchar())b[++n1]=ch-'0';
	ss(0);
	printf("%d\n",ans);
	return 0;
}