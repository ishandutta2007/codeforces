#include <stdio.h>
#include <vector>

std::vector<int> V1,V2;

int findStart(int k)
{
	for(int i=k;i<V1.size();i++)
	{
		if(V1[i]==0&&V2[i]==1) return -1;
		if(V1[i]==1) return i;
	}
	return -1;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V1.clear();
		V2.clear();
		
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		if(a>b)
		{
			printf("NO\n");
			continue;
		}
		
		while(a)
		{
			V1.push_back(a%2);
			a/=2;
		}
		while(b)
		{
			V2.push_back(b%2);
			b/=2;
		}
		for(int i=V1.size();i<V2.size();i++) V1.push_back(0);
		
		for(int i=0;i<V2.size();i++)
		{
			if(V2[i]==1)
			{
				for(int j=0;j<=i;j++)
				{
					if(V1[j]==1)
					{
						V1[j] = 0;
						goto v;
					}
				}
				printf("NO\n");
				goto u;
				v:;
			}
		}
		
		printf("YES\n");
		u:;
	}
}