// Hydro submission #62c048f389ffbb18f0fee574@1656768756106
#include<bits/stdc++.h>
using namespace std;
int t,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int k=0;
		while(1<<(k+1)<=(n-1)) 
		{
			k++;
		}
		for(int i=(1<<k)-1;i>=0;i--) 
		{
			printf("%d ",i);
		}
		for(int i=(1<<k);i<n;i++) 
		{
			printf("%d ",i);
		}
		printf("\n");
	}
	return 0;
}