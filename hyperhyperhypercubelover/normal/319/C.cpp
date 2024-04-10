#include<cstdio>
#include<algorithm>

std::pair<int,long long> s[100000];
int sn;

int a[100000];
int b[100000];
long long d[100000];

void insert(int a,long long b)
{
	double t;
    while(sn>=2)
	{
		t = -1.*(s[sn-1].second-s[sn-2].second)/(s[sn-1].first-s[sn-2].first);
        if(t*a+b>t*s[sn-1].first+s[sn-1].second)break;
        sn--;
	}
	s[sn++]=std::make_pair(a,b);
}

long long calc(int x)
{
    int l=0,r=sn-1,mid;
    double t;
    while(l<r)
	{
        mid=(l+r)/2;
        t = -1.*(s[mid+1].second-s[mid].second)/(s[mid+1].first-s[mid].first);
        if(t<x)l=mid+1;
        else r=mid;
	}
	return 1LL*x*s[l].first+s[l].second;
}

int main()
{
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++)scanf("%d",&a[i]);
	for(i=0;i<n;i++)scanf("%d",&b[i]);
    for(i=1;i<n;i++)
	{
		insert(b[i-1],d[i-1]);
		d[i]=calc(a[i]);
	}
	printf("%I64d",d[n-1]);
}