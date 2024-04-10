#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
struct node
{
	int lx,rx,ly,ry;
	node operator+(const node& y)const
	{
		node t;
		t.lx=max(lx,y.lx);
		t.ly=max(ly,y.ly);
		t.rx=min(rx,y.rx);
		t.ry=min(ry,y.ry);
		return t;
	}
}a[MAXN],b[MAXN],c[MAXN],d;
int n,i;
int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)scanf("%d%d%d%d",&a[i].lx,&a[i].ly,&a[i].rx,&a[i].ry);
	for(b[1]=a[1],i=2;i<=n;i++)b[i]=b[i-1]+a[i];
	for(c[n]=a[n],i=n-1;i;i--)c[i]=c[i+1]+a[i];
	for(i=1;i<=n;i++)
	{
		if(i==1)d=c[2];
		else if(i==n)d=b[n-1];
		else d=c[i+1]+b[i-1];
		if(d.lx<=d.rx&&d.ly<=d.ry)
		{
			cout<<d.lx<<' '<<d.ly<<endl;
			break;
		}
	}
	return 0;
}