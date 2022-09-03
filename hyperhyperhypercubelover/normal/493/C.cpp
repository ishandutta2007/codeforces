#include<cstdio>
#include<algorithm>

std::pair<int,int> a[444444];

int main()
{
	int mx,my;
	int x,y;
	int i,n,m;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i].first);
        a[i].second=-1;
	}
	scanf("%d",&m);
	for(i=0;i<m;i++)
	{
		scanf("%d",&a[i+n].first);
        a[i+n].second=1;
	}
	std::sort(a,a+n+m);
	x=n*3;y=m*3;
	mx=x;my=y;
    for(i=0;i<n+m;i++)
    {
		if(a[i].second==1)y--;
		else x--;
		if(x-y>mx-my)
		{
			mx=x;
			my=y;
		}
    }
    printf("%d:%d\n",mx,my);
}