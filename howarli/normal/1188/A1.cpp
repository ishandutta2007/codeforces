#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
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
// int B[N*2][2],A[N],B0;
int Bv[N];
void link(int q,int w)
{
	++Bv[q],++Bv[w];
	// B[++B0][0]=A[q],A[q]=B0,B[B0][1]=w;
	// B[++B0][0]=A[w],A[w]=B0,B[B0][1]=q;
}
// void dfs(int q,int fa)
// {
// 	int cnt=0;
// 	efo(i,q)if(B[i][1]!=fa)
// 	{
// 		++cnt;
// 		if(Bv[B[i][1]]>1)
// 		{
// 			if(Bv[q]<3)ans=1;
// 		}else 
// 		dfs(B[i][1],q);
// 	}
// 	if(cnt)
// 	{

// 	}
// }
int main()
{
	int q,w;
	read(n);
	fo(i,1,n-1)read(q),read(w),link(q,w);
	// dfs(1,0);
	fo(i,1,n)if(Bv[i]==2)ans=1;
	if(ans&&n>2)printf("NO\n");
	else printf("YES\n");
	return 0;
}