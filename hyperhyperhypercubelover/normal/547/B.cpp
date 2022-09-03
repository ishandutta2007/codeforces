#include<cstdio>
#include<algorithm>

int a[222222];
int t[222222];
std::pair<int,int> d[222222];
int v[222222];
int p[222222];
int s[222222];

int par(int x){return p[x]==x?x:p[x]=par(p[x]);}
void com(int x,int y){s[par(y)]+=s[par(x)];p[par(x)]=par(y);}

int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
		d[i].first=a[i];
		d[i].second=i;
		p[i]=i;
		s[i]=1;
	}
	std::sort(d,d+n);
	for(i=n-1;i>=0;i--)
	{
        v[d[i].second]=1;
		if(d[i].second>0&&v[d[i].second-1])com(d[i].second-1,d[i].second);
        if(d[i].second<n-1&&v[d[i].second+1])com(d[i].second+1,d[i].second);
        t[s[par(d[i].second)]]=std::max(t[s[par(d[i].second)]],d[i].first);
	}
    for(i=n-1;i>0;i--)t[i]=std::max(t[i],t[i+1]);
    for(i=1;i<=n;i++)printf("%d ",t[i]);
}