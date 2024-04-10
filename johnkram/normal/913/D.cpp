#include<bits/stdc++.h>
using namespace std;
struct node
{
	int a,b,i;
	bool operator<(const node& y)const
	{
		return a>y.a;
	}
}a[200005];
int n,m,i,j,ans,s1[100005],s2[100005];
void fix(int R,int l,int r,int x)
{
	s1[R]+=x;
	s2[R]++;
	if(l==r)return;
	int mid=l+r>>1;
	if(x<=mid)fix(R<<1,l,mid,x);
	else fix(R<<1|1,mid+1,r,x);
}
int ask(int R,int l,int r,int x,int y)
{
	if(s1[R]<=x&&s2[R]<=y)return s2[R];
	if(l==r)return min(x/l,y);
	int mid=l+r>>1;
	if(s1[R<<1]>x||s2[R<<1]>y)return ask(R<<1,l,mid,x,y);
	return s2[R<<1]+ask(R<<1|1,mid+1,r,x-s1[R<<1],y-s2[R<<1]);
}
bool cmp(node x,node y)
{
	return x.b<y.b;
}
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&a[i].a,&a[i].b);
		a[i].i=i;
	}
	sort(a+1,a+n+1);
	for(i=n,j=1;i;i--)
	{
		for(;j<=n&&a[j].a==i;j++)fix(1,1,10000,a[j].b);
		ans=max(ans,ask(1,1,10000,m,i));
	}
	for(i=1;i<=n;i++)if(a[i].a<ans)break;
	sort(a+1,a+i,cmp);
	printf("%d\n%d\n",ans,ans);
	for(i=1;i<=ans;i++)printf("%d ",a[i].i);
	return 0;
}