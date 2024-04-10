#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long long LL;
typedef long double lb;
#define ri register int
const lb PI=3.141592653589793238462643383279;
const ll inf=1000000000000000000ll;
const int N=500005,M=998244353;
int t,i,ans[N],p;
char c[N]; 
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",c+1);
		int n=strlen(c+1);
		p=0;
		for(i=1;i<=n-2;++i)
		{
			if(c[i]=='o'&&c[i+1]=='n'&&c[i+2]=='e')
			{
				if(c[i+2]!=c[i+3])
				{
					ans[++p]=i+2;
					i+=2;
				}
				else
				{
					ans[++p]=i+1;
					++i;
				}
			}
			if(c[i]=='t'&&c[i+1]=='w'&&c[i+2]=='o')
			{
				if(c[i+2]!=c[i+3])
				{
					ans[++p]=i+2;
					i+=2;
				}
				else
				{
					ans[++p]=i+1;
					++i;
				}
			}
		}
		printf("%d\n",p);
		for(i=1;i<=p;++i)
			printf("%d ",ans[i]);
		printf("\n");
	}
}