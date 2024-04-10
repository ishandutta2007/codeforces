#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long LL;
const int N=600500;
int read(int &n)
{
	bool q=0;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),q=1;
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<3)+(n<<1)+ch-48;
	return q?n=-n:n;
}
int n,m,K;
int a[N];
int Fa[N],zx[N];
int f[N];
void JS(int q)
{
	for(;q;q=Fa[q])
	{
		if(a[q]=='0')f[q]=f[zx[q]];
		else if(a[q]=='1')f[q]=f[zx[q]+1];
		else f[q]=f[zx[q]]+f[zx[q]+1];
	}
}

int main()
{
	int q,w,_;
	read(K);
	char ch=' ';
	for(;(ch<'0'||ch>'9')&&ch!='?';ch=getchar());
	for(n=0;(ch<='9'&&ch>='0')||ch=='?';ch=getchar())a[++n]=ch;
	for(int i=n-1,j=n;i>=1;i-=2,--j)
	{
		zx[j]=i-1;
		Fa[i]=j;
		Fa[i-1]=j;
	}
	q=1<<(K-1);
	f[n+1]=f[n+2]=1;
	fo(i,1,q)zx[i]=n+1;

	fo(i,1,q)JS(i);
	read(m);
	fo(i,1,m)
	{
		read(q);
		char ch=' ';
		for(;(ch<'0'||ch>'9')&&ch!='?';ch=getchar());

		a[q]=ch;
		JS(q);
		printf("%d\n",f[n]);
	}






	return 0;
}