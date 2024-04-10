/****************************************************************
*	Author: huhao
*	Email: 826538400@qq.com
*	Create time: 2019-10-16 22:47:27
****************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
#define fr(i,a,b) for(int i=(a),end_##i=(b);i<=end_##i;i++)
#define fd(i,a,b) for(int i=(a),end_##i=(b);i>=end_##i;i--)
int read()
{
	int r=0,t=1,c=getchar();
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
const int N=50010;
struct point
{
	int x,y,z,id;
}a[N];
int cmp(point a,point b)
{
	return a.x!=b.x?a.x<b.x:
	a.y!=b.y?a.y<b.y:a.z<b.z;
}
int n,p[N];
int main()
{
	n=read();
	fr(i,1,n)
	{
		a[i].x=read();
		a[i].y=read();
		a[i].z=read();
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	fr(l,1,n)
	{
		int r=l;
		while(a[r+1].x==a[l].x&&r<n)
			r++;
		fr(L,l,r)
		{
			int R=L;
			while(a[R+1].y==a[L].y&&R<r)
				R++;
			fr(i,L,R)
				if(i!=R)
				{
					p[i]=1;
					p[i+1]=1;
					printf("%d %d\n",a[i].id,a[i+1].id);
					i++;
				}
			L=R;
		}
		int lst=0;
		fr(i,l,r)
			if(!p[i])
			{
				if(lst)
				{
					p[i]=p[lst]=1;
					printf("%d %d\n",a[i].id,a[lst].id);
					lst=0;
				}
				else
					lst=i;
			}
		l=r;
	}
	int lst=0;
	fr(i,1,n)
		if(!p[i])
		{
			if(lst)
			{
				p[i]=p[lst]=1;
				printf("%d %d\n",a[i].id,a[lst].id);
				lst=0;
			}
			else
				lst=i;
		}
	return 0;
}