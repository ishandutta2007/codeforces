#include<cstdio>
#include<algorithm>

std::pair<int,int> a[100000];
std::pair<int,int> b[100000];
int t[200000];
int v[100000];
int c;

int fac(int n,int m)
{
	if(n==0)return 1;
	if(c&&n%2==0)
	{
		c--;
		return 1LL*n/2*fac(n-1,m)%m;
	}
    return 1LL*n*fac(n-1,m)%m;
}

int main()
{
	int x,y;
	int i,j,n,m,r=1;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second=i;
		t[i]=a[i].first;
	}
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i].first);
		b[i].second=i;
		t[i+n]=b[i].first;
	}
	scanf("%d",&m);
	std::sort(a,a+n);
	std::sort(b,b+n);
    std::sort(t,t+n+n);
    for(i=0;i<n+n;i++)if(!i||t[i]!=t[i-1])
	{
		x=std::lower_bound(a,a+n,std::make_pair(t[i],0))-a;
		y=std::upper_bound(a,a+n,std::make_pair(t[i],n))-a;
		for(j=x;j<y;j++)v[a[j].second]=1;
		c=0;
		x=std::lower_bound(b,b+n,std::make_pair(t[i],0))-b;
		y=std::upper_bound(b,b+n,std::make_pair(t[i],n))-b;
		for(j=x;j<y;j++)c+=v[b[j].second];
		x=std::lower_bound(a,a+n,std::make_pair(t[i],0))-a;
		y=std::upper_bound(a,a+n,std::make_pair(t[i],n))-a;
		for(j=x;j<y;j++)v[a[j].second]=0;
		j=std::upper_bound(a,a+n,std::make_pair(t[i],n))-std::lower_bound(a,a+n,std::make_pair(t[i],0))+std::upper_bound(b,b+n,std::make_pair(t[i],n))-std::lower_bound(b,b+n,std::make_pair(t[i],0));
		r=1LL*r*fac(j,m)%m;
	}
	printf("%d",r);
}