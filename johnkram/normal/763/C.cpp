#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
inline void readi(int &x);
const int maxn=1000005;
int n,m,G;
int a[maxn],x[maxn],y[maxn],z[maxn],t[maxn];

inline int ra(){return (rand()<<15^rand())&(~0u>>1);}

inline int gcd(const int &a,const int &b)
{return b?gcd(b,a%b):a;}

void init()
{
	readi(n),readi(m);
	G=n;
	x[0]=n;
	for(int i=1;i<=m;i++)
		readi(x[i]);
	sort(x+1,x+m+1);
	for(int i=1;i<=m;i++)G=gcd(G,x[i]-x[1]);
	if(m==1)
	{
		printf("%d 1\n",x[1]);
		exit(0);
	}
	if(m==n/G)
	{
		printf("%d %d\n",x[1],G);
		exit(0);
	}
	for(int i=1;i<=m;i++)
		a[i]=x[i]/G;
}

map<int,int> cnt;

int work(int *x,int n,int m,int times=0)
{
	if(times>40)return -1;
	if(m<=50)
	{
		cnt.clear();
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				if(i!=j)
				{
					int d=(x[i]-x[j]+n)%n;
					if(gcd(d,n)==1&&++cnt[d]==m-1)
						return d;
				}
		return -1;
	}
	if(m==n-1)return 1;
	int w=x[ra()%m+1],my=0,mz=0,mt=0;
	if(w+w<n)
		for(int i=1;i<=m;i++)
		{
			if(w+w-x[i]<0)y[++my]=w+w-x[i]+n;
			else z[++mz]=w+w-x[i];
		}
	else
		for(int i=1;i<=m;i++)
		{
			if(w+w-x[i]<n)y[++my]=w+w-x[i];
			else z[++mz]=w+w-x[i]-n;
		}
	for(int i=1,j=my,k=mz;i<=m;i++)
	{
		while(j&&y[j]<x[i])j--;
		while(k&&z[k]<x[i])k--;
		if((!j||x[i]!=y[j])&&(!k||x[i]!=z[k]))
			t[++mt]=x[i];
	}
	if(mt>1)
	{
		memcpy(x,t,mt+1<<2);
		return work(x,n,mt,times+1);
	}
	return work(x,n,m,times+1);
}

int main()
{
	init();
	int d=work(a,n/G,m);
	if(d==-1)return puts("-1"),0;
	d*=G;
	int s=x[1],cf=0;
	for(int i=1;i<=m;i++)
		if(!binary_search(x+1,x+m+1,(x[i]+d)%n))
		{
			cf++;
			s=x[i];
		}
	if(cf<=1)
		printf("%d %d\n",s,(n-d)%n);
	else puts("-1");
	return 0;
}

inline void readi(int &x)
{char c;while(c=getchar(),c<'0'||c>'9');
x=c-'0';while(c=getchar(),c>='0'&&c<='9')x=x*10+c-'0';}