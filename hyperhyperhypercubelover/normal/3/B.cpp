#include<cstdio>
#include<algorithm>

std::pair<int,int> a[100000];
std::pair<int,int> b[100000];
int an,bn;

int main()
{
	int max=0,maxi,now=0;
	int i,j,n,m;
	scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++)
    {
		scanf("%d",&j);
		if(j==1)
		{
			scanf("%d",&a[an].first);
			a[an].second=i;
			an++;
		}
		else
		{
			scanf("%d",&b[bn].first);
			b[bn].second=i;
			bn++;
		}
    }
    std::sort(a,a+an);
    std::reverse(a,a+an);
    std::sort(b,b+bn);
    std::reverse(b,b+bn);
    for(i=0;i<an&&m;i++)
	{
		now+=a[i].first;
		m--;
	}
	j=0;
	while(j<bn&&m>1)
	{
		now+=b[j].first;
		m-=2;
		j++;
	}
	max=now;
	maxi=i;
	while(i>0)
	{
        i--;
        now-=a[i].first;
        m++;
        while(j<bn&&m>1)
		{
			now+=b[j].first;
			m-=2;
			j++;
		}
        if(now>max)
		{
			max=now;
			maxi=i;
		}
	}
	m+=j*2;
    printf("%d\n",max);
    for(i=0;i<maxi;i++)printf("%d ",a[i].second);
    for(j=0;j<bn&&j<(m-maxi)/2;j++)printf("%d ",b[j].second);
}