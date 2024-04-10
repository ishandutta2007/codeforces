#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 998244353
#define MAXN 600005
int t,a,b,c,d,n;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(a>(ll)b*c)
		{
			puts("-1");
			continue;
		}
		n=a/b/d;
		cout<<(ll)(a+a-(ll)d*b*n)*(n+1)/2<<endl;
	}
	return 0;
}