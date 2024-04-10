#include<bits\stdc++.h>
using namespace std;

int main()
{
	int n,a,b,cnt=0;
	
	scanf("%d%d%d",&n,&a,&b);
	
	int i;
	
	for (i=0;i*a<=n;i++)
	{
		if ((n-i*a)%b==0)
		{
			int j;
			
			for (j=1;i*a+j*b<=n;j++)
			{
				int k,t=++cnt;
				
				for (k=1;k<b;k++) printf("%d ",++cnt);
				printf("%d ",t);
			}
			
			while (i--)
			{
				int k,t=++cnt;
				
				for (k=1;k<a;k++) printf("%d ",++cnt);
				printf("%d ",t);
			}
			
			return 0;
		}
	}
	
	printf("-1");
	
	return 0;
}