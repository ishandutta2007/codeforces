#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define fr(i,a,b) for(long long i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(long long i=(a),_end_=(b);i>=_end_;i--)
long long read()
{
	long long t=1,r=0,c=getchar();
	while(c<'0'||c>'9')
	{
		t=c=='-'?-1:1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		r=(r<<3)+(r<<1)+(c^48);
		c=getchar();
	}
	return r*t;
}
#define N 100010
long long n,x[N],y[N],use[N];
void print(int a,int b)
{
	fr(i,1,n)
		if((x[i]-x[a])*(y[i]-y[b])==(x[i]-x[b])*(y[i]-y[a]))
			use[i]=1;
}
//(xc-xa)*(yc-yb)=(xc-xb)*(yc-ya)
bool run(int a,int b)
{
	fr(i,1,n)use[i]=0;
	print(a,b);
	int u=0;
	fr(i,1,n)
		if(!use[i])
			if(u)
			{
				print(u,i);
				fr(j,1,n)
					if(!use[j])
						return 0;
				return 1;
			}
			else u=i;
	return 1;
}
int main()
{
	n=read();
	fr(i,1,n)
		x[i]=read(),y[i]=read();
	if(run(1,2)||run(1,3)||run(2,3))printf("YES\n");
	else printf("NO\n");
	return 0;
}