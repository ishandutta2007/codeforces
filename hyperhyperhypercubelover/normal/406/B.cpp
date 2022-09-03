#include<cstdio>
#include<algorithm>

bool d[1000001];
int r[1000000],rn;

int main()
{
	int i,n,a;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a);
		d[a]=true;
	}
	a=0;
	for(i=1;i<=1000000;i++)
	{
		if(d[i]&&!d[1000000-i+1])r[rn++]=1000000-i+1;
		else if(d[i]&&d[1000000-i+1])a++;
	}
	for(i=1;i<=1000000;i++)if(a&&!d[i]&&!d[1000000-i+1])
	{
		a-=2;
		r[rn++]=i;
		r[rn++]=1000000-i+1;
	}
	std::sort(r,r+rn);
	printf("%d\n",rn);
	for(i=0;i<rn;i++)printf("%d ",r[i]);
}