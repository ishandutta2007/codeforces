#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define max(q,w) ((q)>(w)?(q):(w))
#define min(q,w) ((q)<(w)?(q):(w))
#define PR(...) printf(__VA_ARGS__)
using namespace std;
const int N=100500;
int read(int &n)
{
	int w=1;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch<='9'&&ch>='0';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return n=n*w;
}
int n,m,ans;
int B[N*4][3],A[N],B0=1;
int Bv[N];
int Ans[N*4][3];
int root;
int z[N];
void link(int q,int w,int e)
{
	++Bv[q],++Bv[w];
	B[++B0][0]=A[q],A[q]=B0,B[B0][1]=w,B[B0][2]=e;
	B[++B0][0]=A[w],A[w]=B0,B[B0][1]=q,B[B0][2]=e;
}
int f[N][2];
int dfsf(int q,int fa)
{
	f[q][0]=f[q][1]=q;
	efo(i,q)if(B[i][1]!=fa&&!z[B[i][1]])
	{
		if(f[q][0]==q)f[q][1]=f[q][0]=dfsf(B[i][1],q);
		else f[q][1]=dfsf(B[i][1],q);
	}
	return f[q][0];
}
void OPT(int q,int w,int x,int y,int e)
{
	Ans[++ans][0]=q,Ans[ans][1]=x,Ans[ans][2]=e/2;
	Ans[++ans][0]=w,Ans[ans][1]=y,Ans[ans][2]=e/2;
	if(q!=w)Ans[++ans][0]=q,Ans[ans][1]=w,Ans[ans][2]=-e/2;
	if(x!=y)Ans[++ans][0]=x,Ans[ans][1]=y,Ans[ans][2]=-e/2;
	// printf("%d %d %d\n",q,x,e/2);
	// printf("%d %d %d\n",w,y,e/2);
	// if(q!=w)printf("%d %d %d\n",q,w,-e/2);
	// if(x!=y)printf("%d %d %d\n",x,y,-e/2);
}
void dfs(int q,int fa,int e)
{
	if(f[q][0]==q)return;
	int e1=f[q][0],e2=f[q][1];
	efo(i,q)if(B[i][1]!=fa&&!z[B[i][1]])
	{
		if(!e&&f[B[i][1]][0]!=e1&&f[B[i][1]][0]!=e2)e=f[B[i][1]][0];
	}
	efo(i,q)if(B[i][1]!=fa&&!z[B[i][1]])
	{
		int w=B[i][1];
		if(e==f[B[i][1]][0])
		{
			OPT(e1,e2,f[w][0],f[w][1],B[i][2]);
			dfs(B[i][1],q,e1);
		}else if(e1==f[B[i][1]][0])
		{
			OPT(e,e2,f[w][0],f[w][1],B[i][2]);
			dfs(B[i][1],q,e);
		}else 
		{
			OPT(e1,e,f[w][0],f[w][1],B[i][2]);
			dfs(B[i][1],q,e1);
		}		
	}
}
int main()
{
	int q,w,e;
	read(n);
	fo(i,1,n-1)read(q),read(w),read(e),link(q,w,e);
	// ans=0;
	// fo(i,1,n)if(Bv[i]==2)ans=1;
	// if(ans)return printf("NO\n"),0;
	// printf("YES\n");
	if(n==2)
	{	
		printf("YES\n");
		printf("1\n");
		printf("%d %d %d\n",1,2,B[2][2]);
		return 0;
	}
	fo(i,1,n)if(Bv[i]>2)root=i;
	if(!root)
	{
		fo(i,3,B0)if(B[i-1][2]!=B[i][2])return printf("NO\n"),0;
		q=w=0;
		fo(i,1,n)if(Bv[i]==1)
		{
			if(!q)q=i;
			else w=i;
		}
		printf("YES\n");
		printf("1\n");
		printf("%d %d %d\n",q,w,B[2][2]);
		return 0;
	}
	fo(i,1,n)if(Bv[i]==2&&!z[i])
	{
		if(B[A[i]][2]!=B[B[A[i]][0]][2])return printf("NO\n"),0;
		z[i]=1;
		for(q=B[A[i]][1];Bv[q]==2;q=(z[B[A[q]][1]]?B[B[A[q]][0]][1]:B[A[q]][1]))
		{
			if(B[A[q]][2]!=B[B[A[q]][0]][2])return printf("NO\n"),0;
			z[q]=1;
		}
		for(w=B[B[A[i]][0]][1];Bv[w]==2;q=(z[B[A[w]][1]]?B[B[A[w]][0]][1]:B[A[w]][1]))
		{
			if(B[A[w]][2]!=B[B[A[w]][0]][2])return printf("NO\n"),0;
			z[w]=1;
		}
		--Bv[q],--Bv[w];
		link(q,w,B[A[i]][2]);
	}


	dfsf(root,0);
	dfs(root,0,0);
	printf("YES\n");
	printf("%d\n",ans);
	fo(i,1,ans)printf("%d %d %d\n",Ans[i][0],Ans[i][1],Ans[i][2]);
	return 0;
}