#include<bits/stdc++.h>
using namespace std;
int n,m,M,i,j,k,l,o,x[55],y[55],a1[20000],a2[20000],a3[20000],a4[20000];
bool c[55];
struct node
{
	int x,y,i;
	bool operator<(const node& b)const
	{
		if(x==b.x)return y<b.y;
		return x<b.x;
	}
}a[55],b[55];
void move(int a,int b,int c,int d)
{
	a1[++M]=a;
	a2[M]=b;
	a3[M]=c;
	a4[M]=d;
}
int main()
{
	scanf("%d%d",&n,&m);
	if(n==1)
	{
		puts("0");
		return 0;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].i=i;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&b[i].x,&b[i].y);
		b[i].i=i;
	}
	sort(a+1,a+m+1);
	sort(b+1,b+m+1);
	for(i=1;i<=m;i=j)
	{
		for(j=i+1;j<=m&&a[j].x==a[i].x;j++);
		for(k=i;k<j;k++)if(a[k].y>=k)break;
		for(l=k-1;l>=i;l--)for(o=a[l].y;o<l;o++)move(a[i].x,o,a[i].x,o+1);
		for(l=k;l<j;l++)for(o=a[l].y;o>l;o--)move(a[i].x,o,a[i].x,o-1);
		for(k=i;k<j;k++)for(l=a[i].x;l>1;l--)move(l,k,l-1,k);
	}
	if(n==2&&m==2&&a[1].i!=b[1].i)
	{
		move(1,1,2,1);
		move(2,1,2,2);
		move(1,2,1,1);
		move(2,2,1,2);
	}
	else
	{
		for(i=1;i<=m;i++)x[b[i].i]=i;
		for(i=1;i<=m;i++)y[x[a[i].i]]=i;
		for(i=1;i<=m;i++)x[y[i]]=i;
		for(i=1;i<=m;i++)if(y[i]!=i&&!c[i])
		{
			c[i]=1;
			for(k=1;k<3;k++)move(k,i,k+1,i);
			for(j=y[i];j!=i;j=y[j])
			{
				c[j]=1;
				move(1,j,2,j);
				if(x[j]<=j)for(k=j;k>x[j];k--)move(2,k,2,k-1);
				else for(k=j;k<x[j];k++)move(2,k,2,k+1);
				move(2,x[j],1,x[j]);
			}
			if(x[j]<=j)for(k=j;k>x[j];k--)move(3,k,3,k-1);
			else for(k=j;k<x[j];k++)move(3,k,3,k+1);
			for(k=3;k>1;k--)move(k,x[i],k-1,x[i]);
		}
	}
	for(i=m;i;i=j)
	{
		for(j=i-1;j&&b[j].x==b[i].x;j--);
		for(k=i;k>j;k--)for(l=1;l<b[i].x;l++)move(l,k,l+1,k);
		for(k=i;k>j;k--)if(b[k].y<=k)break;
		for(l=j+1;l<=k;l++)for(o=l;o>b[l].y;o--)move(b[i].x,o,b[i].x,o-1);
		for(l=i;l>k;l--)for(o=l;o<b[l].y;o++)move(b[i].x,o,b[i].x,o+1);
	}
	cout<<M<<endl;
	for(i=1;i<=M;i++)cout<<a1[i]<<' '<<a2[i]<<' '<<a3[i]<<' '<<a4[i]<<endl;
	return 0;
}