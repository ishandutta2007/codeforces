#include<cstdio>
#include<algorithm>
#include<vector>

int n,m;
int a[333333];
int d[333333];
std::pair<int,int> b[333333];
std::vector<int> v[1111111];

int vv[333333];
int p[333333];
int ll[333333],rr[333333];

int cnt(int l,int r,int m)
{
	return std::lower_bound(v[m].begin(),v[m].end(),r)-std::lower_bound(v[m].begin(),v[m].end(),l);
}

int par(int x){return x==p[x]?x:p[x]=par(p[x]);}
void com(int x,int y){x=par(x);y=par(y);ll[y]=std::min(ll[y],ll[x]);rr[y]=std::max(rr[y],rr[x]);p[x]=y;}

int main()
{
	long long res=0;
	int i,j,t,l,r;
	scanf("%d%d",&n,&m);
	v[0].push_back(0);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&t);
        a[i]=(a[i-1]+t)%m;
        v[a[i]].push_back(i);
		b[i].first=t;
		b[i].second=i;
	}
	std::sort(b+1,b+n+1);
	for(i=1;i<=n;i++)p[i]=ll[i]=rr[i]=i;
	for(i=1;i<=n;i++)
	{
		vv[b[i].second]=1;
        if(vv[b[i].second-1])com(b[i].second-1,b[i].second);
        if(vv[b[i].second+1])com(b[i].second+1,b[i].second);
        l=ll[b[i].second];
        r=rr[b[i].second];
        if(b[i].second-l<r-b[i].second)for(j=l-1;j<b[i].second;j++)res+=cnt(b[i].second,r+1,(a[j]+b[i].first)%m);
        else for(j=b[i].second;j<r+1;j++)res+=cnt(l-1,b[i].second,(a[j]+m-b[i].first%m)%m);
	}
	printf("%I64d",res-n);
}