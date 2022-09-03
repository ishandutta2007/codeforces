#include<cstdio>
#include<algorithm>

std::pair<int,int> a[111];
std::pair<int,int> b[111];
int an,bn;

int main()
{
    int i,j,n,r=0;
    scanf("%d",&n);
    while(n--)
	{
		scanf("%d%d",&i,&j);
		if(i<0)a[an++]=std::make_pair(-i,j);
		if(i>0)b[bn++]=std::make_pair(i,j);
	}
	std::sort(a,a+an);
	std::sort(b,b+bn);
	for(i=0;i<std::min(an,bn);i++)r+=a[i].second+b[i].second;
    if(an<bn)r+=b[an].second;
    else r+=a[bn].second;
    printf("%d\n",r);
}