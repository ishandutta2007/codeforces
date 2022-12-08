#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
#define PR(...) printf(__VA_ARGS__)
#define EPR(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long LL;
const int N=100500;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n,ans;
int a[N];
bool z[N];
int B[2*N][2],A[N],B0;
void link(int q,int w)
{
	B[++B0][0]=A[q],A[q]=B0,B[B0][1]=w;
	B[++B0][0]=A[w],A[w]=B0,B[B0][1]=q;
}
int main()
{
	int q,w;
	read(n);
	int cnt2=0,cnt1=0;
	fo(i,1,n)
	{
		read(q);
		if(q==1)++cnt1;else ++cnt2;
	}
	if(!cnt1||!cnt2)
	{
		fo(i,1,cnt1)PR("1 ");
		fo(i,1,cnt2)PR("2 ");
		return 0;
	}
	PR("2 1 ");
	--cnt2;--cnt1;
	fo(i,1,cnt2)PR("2 ");
	fo(i,1,cnt1)PR("1 ");
	
	
	return 0;
}