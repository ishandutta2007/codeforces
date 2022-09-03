#include<cstdio>
#include<algorithm>

int a[100001];
int BIT[100001];
std::pair<int,int> d[100001];

void update(int x)
{
	while(x<=100000)
	{
		BIT[x]++;
		x+=x&-x;
	}
}

int get(int x)
{
	int r=0;
	while(x)
	{
		r+=BIT[x];
		x-=x&-x;
	}
	return r;
}

int main()
{
	int max=0;
	int l,r,mid;
	int i,n;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		d[i].first=a[i];
		d[i].second=i;
	}
	std::sort(d+1,d+n+1);
	for(i=n;i>=1;i--)
	{
		if(d[i].second>1)
		{
			l=1;
			r=d[i].second-1;
			while(l<r)
			{
				mid=(l+r+1)/2;
				if(get(d[i].second-1)-get(mid-1))l=mid;
				else r=mid-1;
			}
			if(get(l)-get(l-1)&&(d[i].first^a[l])>max)max=d[i].first^a[l];
		}
		if(d[i].second<n)
		{
			l=d[i].second+1;
			r=n;
			while(l<r)
			{
				mid=(l+r)/2;
				if(get(mid)-get(d[i].second))r=mid;
				else l=mid+1;
			}
			if(get(r)-get(r-1)&&(d[i].first^a[r])>max)max=d[i].first^a[r];
		}
        update(d[i].second);
	}
	printf("%d",max);
}