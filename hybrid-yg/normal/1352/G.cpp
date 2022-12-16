#include<bits/stdc++.h>
using namespace std;
const int N=500005,E=524288;
const int M=1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
int n,i,t; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		if(n<=3)
			puts("-1");
		else
		{
			if(n&1)
			{
				for(i=n-1;i>=1;i-=2)
					printf("%d ",i);
				printf("5 ");
				printf("1 ");
				printf("3 ");
				for(i=7;i<=n;i+=2)
					printf("%d ",i);
			}
			else
			{
				for(i=n-1;i>=1;i-=2)
					printf("%d ",i);
				printf("4 ");
				printf("2 ");
				for(i=6;i<=n;i+=2)
					printf("%d ",i);
			}
			printf("\n");
		}
	}
}