#include <cstdio>
#include <algorithm>
#include <iostream>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define fod(i,a,b) for(int i=a;i>=b;--i)
#define efo(i,q) for(int i=A[q];i;i=B[i][0])
#define min(q,w) ((q)>(w)?(w):(q))
#define max(q,w) ((q)<(w)?(w):(q))
using namespace std;
typedef long long LL;
const int N=500500;
int read(int &n)
{
	char ch=' ';int q=0,w=1;
	for(;(ch!='-')&&((ch<'0')||(ch>'9'));ch=getchar());
	if(ch=='-')w=-1,ch=getchar();
	for(;ch>='0' && ch<='9';ch=getchar())q=q*10+ch-48;n=q*w;return n;
}
int n;
LL ans;
int a[N];
int b1[N*2],b2[N*2];//OK L R
bool CEK()
{
	int q=0;
	fo(i,1,a[0])
	{
		q+=a[i];
		if(q<0)return 0;
	}
	return 1;
}
int main()
{
	int q,w,t=0;
	int mi=1e9,mx=-1e9;
	read(n);
	fo(I,1,n)
	{
		char ch=' ';
		for(;ch!='('&&ch!=')';ch=getchar());
		q=w=0;
		for(a[0]=0;ch=='('||ch==')';ch=getchar())
		{
			a[++a[0]]=(ch=='('?1:-1);
			w+=a[a[0]];
		}
		if(CEK()&&w==0){++t;continue;}
		if(CEK())++b1[w];
		mx=max(mx,w);
		fo(i,a[0]/2+1,a[0])swap(a[i],a[a[0]-i+1]);
		fo(i,1,a[0])a[i]=-a[i];
		if(CEK())++b2[-w];
	}
	ans=t/2;
	fo(i,0,mx)ans+=min(b1[i],b2[i]);
	printf("%lld\n",ans);
	return 0;
}