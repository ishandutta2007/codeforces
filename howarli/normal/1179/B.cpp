#include <bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define max(q,w) ((q)<(w)?(w):(q))
#define min(q,w) ((q)>(w)?(w):(q))
using namespace std;
const int N=100500,mo=1e9+7;
int read(int &n)
{
	int w=1;n=0;char ch=' ';
	for(;ch!='-'&&(ch<'0'||ch>'9');ch=getchar());
	if(ch=='-')ch=getchar(),w=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())n=(n<<1)+(n<<3)+ch-48;
	return n=n*w;
}
int n,m,ans;
int a[N];
int x,y;
void Go(int l,int r,int n)
{
	fo(i,1,n)
	{
		printf("%d %d\n",x+=r-l,y+=n-i*2+1);
		if(i<n)printf("%d %d\n",x+=l-r,y+=-(n-i*2));
		else if(l+1!=r)printf("%d %d\n",x+=l-r+1,y+=0);
	}
}
int main()
{
	int q,w;
	read(m),read(n);
	x=y=1;
	printf("1 1\n");
	for(int l=1,r=m;l<=r;++l,--r)
	{
		if(l==r)
		{
			for(l=1,r=n;l<r;++l,--r)
			{
				printf("%d %d\n",x,y+=r-l);
				if(l-r+1!=0)printf("%d %d\n",x,y+=l-r+1);
			}
			break;
		}else Go(l,r,n);
	}
	return 0;
}