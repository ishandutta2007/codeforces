#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
struct ask{
	int c,p,where;
}x[2000];
struct sit{
	int r,where;
}y[2000];
int n,k,r[2000],a[2000],c[2000];
bool compare(ask k1,ask k2)
{
	return k1.p>k2.p;
}
bool compare1(sit k1,sit k2)
{
	return k1.r<k2.r;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d%d",&x[i].c,&x[i].p); x[i].where=i;
	}
	sort(x+1,x+n+1,compare);
	scanf("%d",&k);
	for (int i=1;i<=k;i++){
		scanf("%d",&y[i].r); y[i].where=i;
	}
	sort(y+1,y+k+1,compare1);
	memset(a,0x00,sizeof a);
	memset(c,0x00,sizeof c);
	int tot=0,num=0;
	for (int i=1;i<=n;i++){
		int j;
		for (j=1;j<=k&&(y[j].r<x[i].c||a[j]);j++);
		if (j>k) continue;
		tot+=x[i].p; a[j]=1; c[x[i].where]=y[j].where; num++;
	}
	printf("%d %d\n",num,tot);
	for (int i=1;i<=n;i++) if (c[i]) cout<<i<<" "<<c[i]<<endl;
}