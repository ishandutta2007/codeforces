#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1048576
int t,n,n1,n2,i,ans;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&n1,&n2);
		while(n1--)
		{
			scanf("%d",&i);
			if(i==n)ans=1;
		}
		while(n2--)
		{
			scanf("%d",&i);
			if(i==n)ans=2;
		}
		if(ans==1)puts("YES");
		else puts("NO");
	}
	return 0;
}