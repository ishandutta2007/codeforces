#include<cstdio>
#include<algorithm>

int main()
{
	int i,j,t;
	for(i=0;i<5;i++)for(j=0;j<5;j++)
	{
		scanf("%d",&t);
		if(t)printf("%d",std::abs(i-2)+std::abs(j-2));
	}
}