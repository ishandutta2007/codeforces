#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
inline int read()
{
	int sum=0,p=1;char ch=getchar();
	while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
	if(ch=='-')p=-1,ch=getchar();
	while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
	return sum*p;
}

const int maxn=1e5+20;

int n,a[maxn];

int x[maxn],y[maxn],z[maxn],tot;

int s1[maxn];

inline void Do(int X,int Y,int Z)
{
	//assert(X+Z==2*Y);
	a[X]^=1; a[Y]^=1; a[Z]^=1;
	x[++tot]=X; y[tot]=Y; z[tot]=Z;
}

int vis[maxn];

int main()
{
	n=read();
	REP(i,1,n)s1[i]=a[i]=read();

	if(n<=7)
	{
		
		REP(i,1,n-2)
		{
			if(s1[i])
			{
				s1[i]^=1;s1[i+1]^=1;s1[i+2]^=1;
			}
		}
		if(n<=6)
		{
			if(s1[n-1] || s1[n])puts("NO"),exit(0);
		}
		if(n==7)
		{
			if(s1[n-1])puts("NO"),exit(0);
		}
	}

	for(int i=1;i<=n-11;i++)
	{
		if(a[i])
		{
			if(a[i+1] && a[i+2])
			{
				vis[i]^=1;//Do(i,i+1,i+2);
				a[i]^=1;a[i+1]^=1; a[i+2]^=1;
			}else 
			if(a[i+2])
			{
				Do(i,i+2,i+4);
			}else if(!a[i+1])
			{
				Do(i,i+3,i+6);
			}else
			{
				if(!a[i+3] && !a[i+4] && !a[i+5])
				{
					Do(i,i+4,i+8); Do(i+1,i+4,i+7);
				}else
				{
					if(a[i+3]+a[i+4]+a[i+5]==1)
					{
						if(a[i+3]==1)
						{
							Do(i,i+3,i+6);
							Do(i+1,i+6,i+11);
						}else if(a[i+4]==1)
						{
							Do(i,i+4,i+8);
							Do(i+1,i+6,i+11);
						}else {
							Do(i,i+5,i+10);
							Do(i+1,i+6,i+11);
						}
					}else if(a[i+3]+a[i+4]+a[i+5]==2)
					{
						if(!a[i+3])
						{
							Do(i,i+4,i+8);
							Do(i+1,i+5,i+9);
						}else if(!a[i+4])
						{
							Do(i,i+3,i+6);
							Do(i+1,i+5,i+9);
						}else {
							Do(i,i+3,i+6);
							Do(i+1,i+4,i+7);
						}
					}else
					{
						Do(i+1,i+3,i+5);
						Do(i,i+4,i+8);
					}
					
				}
			}
		}
	}
	REP(i,n-10,n-2)
	{
		if(a[i])
		{
			vis[i]^=1;//Do(i,i+1,i+2);
			a[i]^=1;a[i+1]^=1; a[i+2]^=1;
		}
	}
	REP(i,n-1,n)
	if(a[i])
	{
		vis[i-5]^=1;vis[i-6]^=1;
		Do(i-6,i-3,i);
	}
	REP(i,1,n)if(vis[i])Do(i,i+1,i+2);
	puts("YES");
	printf("%d\n",tot);
	REP(i,1,tot)
	{
		printf("%d %d %d\n",x[i],y[i],z[i]);
	}
	return 0;
}