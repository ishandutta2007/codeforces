#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
#define fr(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define fd(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
int read()
{
	int t=1,r=0,c=getchar();
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
#define N 300010
struct line
{
	int l,r,pos;
}a[N];
int n,ans;
int cmp(line a,line b)
{
	return a.l==b.l?a.r>b.r:a.l<b.l;
}
int main()
{
	n=read();
	fr(i,1,n)
	{
		a[i].pos=i;
		a[i].l=read();
		a[i].r=read();
	}
	sort(a+1,a+n+1,cmp);
	ans=1;
	fr(i,2,n)
		if(a[i].r<=a[ans].r)
		{
			printf("%d %d\n",a[i].pos,a[ans].pos);
			return 0;
		}
		else ans=i;
	printf("-1 -1\n");
	return 0;
}