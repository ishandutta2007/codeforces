#include <cstdio>
#include <algorithm>
#include <iostream>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
using namespace std;
typedef double db;
const int N=100500;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int m,n,ans;
int a[N][2];
int z0,z1;
int gcd(int x,int y){return y?(gcd(y,x%y)):(x);}
int main()
{
	// freopen("!.in","r",stdin);
//	freopen(".out","w",stdout);
	int q,w;
	read(n),read(m);
	ans=m;
	fo(i,1,n)
	{
		read(q);
		q=q%m;
		if(q)ans=gcd(ans,q),z1=1;
		else z0=1;
	}
	z0=1;
	printf("%d\n",z1*(m-1)/ans+z0);
	if(z0)printf("0 ");
	for(q=ans;q<m;q+=ans)printf("%d ",q);
	return 0;
}