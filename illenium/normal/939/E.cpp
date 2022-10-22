#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#define ll long long
#define maxn 500005
#define re register
#define inf 1e9
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

void write(int x)
{
	if(x>=10) write(x/10);
	putchar(x%10+'0');
}

ll sum[maxn],a[maxn];
int cnt=0;

double solve(int x)
{
	double ans=(x*a[cnt]-sum[x])*1.0/(x+1);
	return ans;
}

inline int trisearch(int left,int right)
{
	int midl,midr;
	while(right>left+1)
	{
		midl=(left+right)/2;
		midr=(midl+right)/2;
		if(solve(midl)>=solve(midr)) right=midr;
		else left=midl;
	}
	if(solve(left)>solve(right)) return left;
	return right;
}

int main()
{
	int n;
	n=read();
	int y;
	for(int i=0;i<n;i++)
	{
		y=read();
		if(y==1)
		{
			++cnt;
			scanf("%lld",&a[cnt]);
			sum[cnt]=sum[cnt-1]+a[cnt];
		}
		else
		{
			int xia=trisearch(1,cnt-1);
			printf("%.10f\n",solve(xia));
		}
	}
	return 0;
}