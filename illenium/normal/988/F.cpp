#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int A[maxn],w[maxn],d[maxn],x,n,m;

int main()
{
	memset(w,0x3f,sizeof(w));
	memset(d,0x3f,sizeof(d));
	x=read(); n=read(); m=read();
	while(n--)
	{
		int l=read(),r=read();
		while(l<r) A[l++]=1;
	}
	while(m--)
	{
		int l=read(),r=read();
		w[l]=min(w[l],r);
	}
	d[0]=0;
	for(int i=1;i<=x;i++)
		if(A[i-1])
		{
			for(int j=i-1;j>=0;j--)
				if(w[j]<1e6) d[i]=min(d[i],d[j]+(i-j)*w[j]);
		}
		else d[i]=d[i-1];
	if(d[x]>1e9) puts("-1");
	else printf("%d\n",d[x]);
	return 0;
}