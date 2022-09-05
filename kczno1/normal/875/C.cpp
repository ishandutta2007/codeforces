#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
template <typename T> void chmin(T &x,const T &y)
{
	if(x>y)x=y;
}
typedef long long ll;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=1e5+5;
int n,m;
int *s[N],len[N];
int a[N],num;
struct edge
{
	int x,y;
}l[N];int e;
bool x_xiao(const edge &l1,const edge &l2)
{
	return l1.x<l2.x;
}
bool y_xiao(const edge &l1,const edge &l2)
{
	return l1.y<l2.y;
}

int main()
{
//	freopen("1.in","r",stdin);
	cin>>n>>m;
	rep(i,1,n)
	{
		scanf("%d",len+i);
		s[i]=new int [len[i]+1];
		rep(j,0,len[i]-1) scanf("%d",s[i]+j);
	}
	rep(i,1,n-1)
	{
		int j=0;
		int mj=min(len[i],len[i+1]);
		while(s[i][j]==s[i+1][j]&&j<mj)++j;
		if(j==mj)
		{
			if(len[i+1]<len[i]) goto no;
			continue;
		}
		int x=s[i][j],y=s[i+1][j];
		if(x>y)
		{
			if(a[x]==2) goto no;
			if(a[y]==1) goto no;
			a[x]=1;a[y]=2;
		}
		else l[++e]=(edge){x,y};
	}
	sort(l+1,l+e+1,x_xiao);
	rep(i,1,e)
	{
		if(a[l[i].x]==2) 
		{
			if(a[l[i].y]==1) goto no;
			a[l[i].y]=2;
		}
	}
	sort(l+1,l+e+1,y_xiao);
	per(i,e,1)
	{
		if(a[l[i].y]==1) 
		{
			if(a[l[i].x]==2) goto no;
			a[l[i].x]=1;
		}
	}
	
	puts("Yes");
	num=0;
	rep(i,1,m)num+=bool(a[i]==1);
	printf("%d\n",num);
	rep(i,1,m)
	if(a[i]==1) printf("%d ",i);
	return 0;
	no:puts("No");
}