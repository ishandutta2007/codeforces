#include <cstdio>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
using namespace std;
const int N=1000500;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n,ans;
int B[N][3];
int b[N];
int Ans[N];
int d[N][2];
void dfsf(int q)
{
	if(B[q][0]==1)
	{
		dfsf(B[q][1]),dfsf(B[q][2]);
		b[q]=b[B[q][2]]&b[B[q][1]];
	}else if(B[q][0]==2)
	{
		dfsf(B[q][1]),dfsf(B[q][2]);
		b[q]=b[B[q][2]]|b[B[q][1]];
	}else if(B[q][0]==3)
	{
		dfsf(B[q][1]),dfsf(B[q][2]);
		b[q]=b[B[q][2]]^b[B[q][1]];
	}else if(B[q][0]==4)
	{
		dfsf(B[q][1]);
		b[q]=!b[B[q][1]];
	}else b[q]=B[q][1];
}
void dfs(int q,int c)
{
	Ans[q]=-1;
	if(B[q][0]==1)
	{
		d[c][0]=d[c-1][0&b[B[q][2]]];
		d[c][1]=d[c-1][1&b[B[q][2]]];
		dfs(B[q][1],c+1);
		d[c][0]=d[c-1][0&b[B[q][1]]];
		d[c][1]=d[c-1][1&b[B[q][1]]];
		dfs(B[q][2],c+1);
	}else if(B[q][0]==2)
	{
		d[c][0]=d[c-1][0|b[B[q][2]]];
		d[c][1]=d[c-1][1|b[B[q][2]]];
		dfs(B[q][1],c+1);
		d[c][0]=d[c-1][0|b[B[q][1]]];
		d[c][1]=d[c-1][1|b[B[q][1]]];
		dfs(B[q][2],c+1);
	}else if(B[q][0]==3)
	{
		d[c][0]=d[c-1][0^b[B[q][2]]];
		d[c][1]=d[c-1][1^b[B[q][2]]];
		dfs(B[q][1],c+1);
		d[c][0]=d[c-1][0^b[B[q][1]]];
		d[c][1]=d[c-1][1^b[B[q][1]]];
		dfs(B[q][2],c+1);
	}else if(B[q][0]==4)
	{
		d[c][0]=d[c-1][1];
		d[c][1]=d[c-1][0];
		dfs(B[q][1],c+1);
	}else 
	{
		Ans[q]=d[c-1][!b[q]];
	}
}
int main()
{
	// freopen("!.in","r",stdin);
//	freopen(".out","w",stdout);
	int q,w;
	read(n);
	fo(i,1,n)
	{
		char ch=' ';
		for(;ch<'A'||ch>'Z';ch=getchar());
		if(ch=='A')
		{
			B[i][0]=1;read(B[i][1]),read(B[i][2]);
		}else if(ch=='O')
		{
			B[i][0]=2;read(B[i][1]),read(B[i][2]);
		}else if(ch=='X')
		{
			B[i][0]=3;read(B[i][1]),read(B[i][2]);
		}else if(ch=='N')
		{
			B[i][0]=4;read(B[i][1]);
		}else if(ch=='I')
		{
			B[i][0]=5;read(B[i][1]);
		}
	}
	dfsf(1);
	d[0][1]=1;
	dfs(1,1);
	fo(i,1,n)if(Ans[i]>=0)printf("%d",Ans[i]);printf("\n");
	return 0;
}