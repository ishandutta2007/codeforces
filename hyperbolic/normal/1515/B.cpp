#include <stdio.h>
#include <map>

std::map<int,int> M;
int main()
{
	for(int i=1;i*i<=1e9;i++) M[i*i] = 1;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		if(a%2==0)
		{
			if(M[a/2]==1)
			{
				printf("YES\n");
				continue;
			}
		}
		if(a%4==0)
		{
			if(M[a/4]==1)
			{
				printf("YES\n");
				continue;
			}
		}
		printf("NO\n");
	}
}