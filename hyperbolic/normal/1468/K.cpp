#include <stdio.h>
#include <vector>
#include <string.h>

std::pair<int,int> func(std::pair<int,int> P, char C)
{
	if(C=='L') return std::make_pair(P.first-1,P.second);
	if(C=='R') return std::make_pair(P.first+1,P.second);
	if(C=='U') return std::make_pair(P.first,P.second+1);
	if(C=='D') return std::make_pair(P.first,P.second-1);
}

char x[5010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		std::pair<int,int> start = std::make_pair(0,0);
		for(int i=1;i<=a;i++)
		{
			start = func(start,x[i]);
			if(start!=std::make_pair(0,0))
			{
				std::pair<int,int> P = std::make_pair(0,0);
				for(int j=1;j<=a;j++)
				{
					if(func(P,x[j])!=start) P = func(P,x[j]);
				}
				if(P==std::make_pair(0,0))
				{
					printf("%d %d\n",start.first,start.second);
					goto u;
				}
			}
		}
		printf("0 0\n");
		u:;
	}
}