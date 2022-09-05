#include<bits/stdc++.h>
using namespace std;

#define rep(i,l,r) for(int i=l;i<=r;++i)
int n,a[1005],b[1005],cnt[1005];
void check(int x,int y)
{
	memset(cnt,0,sizeof(cnt));
	rep(i,1,n)
	if(i!=x&&i!=y)++cnt[a[i]];
	int x1=0,x2=0;
	rep(i,1,n)
	{
		if(cnt[i]>1)return ;
		if(!cnt[i]){x2=i;if(!x1)x1=i;}
	}
	if(x==y) 
	{
		if(!(x1!=a[x]&&x1!=b[x])) return ;
	}
	else
	{
	  if(!(x1==b[x]&&x2==a[y])) swap(x1,x2);
	  if(!(x1==b[x]&&x2==a[y])) return ;
	}
	a[x]=x1;a[y]=x2;
	rep(i,1,n) printf("%d ",a[i]);
	exit(0);
}

int main()
{
    scanf("%d",&n);
    rep(i,1,n)scanf("%d",a+i);
    rep(i,1,n)scanf("%d",b+i);
    int x1=0,x2=0;
    rep(i,1,n)
    if(a[i]!=b[i])
     (x1?x2:x1)=i;
    if(x2){check(x1,x2);check(x2,x1);}
    rep(i,1,n){check(x1,i);check(i,x1);}
}