#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,m,i;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(m<n||!(n&1)&&(m&1))
		{
			puts("No");
			continue;
		}
		puts("Yes");
		if(n&1)
		{
			for(i=1;i<n;i++)printf("1 ");
			printf("%d\n",m-n+1);
		}
		else
		{
			for(i=1;i+1<n;i++)printf("1 ");
			printf("%d %d\n",m-n+2>>1,m-n+2>>1);
		}
	}
	return 0;
}