#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
		int n,x[2000],d[2000];scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
				scanf("%d%d",&x[i],&d[i]);
		}
		for(int i=0;i<n-1;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if((x[i]+d[i]==x[j])&&(x[j]+d[j]==x[i]))
				{
					printf("YES\n");
					return 0;
				}
			}
		}
		printf("NO\n");
		return 0;
}