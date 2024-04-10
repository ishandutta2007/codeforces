#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
ll n,m,i;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		if(n!=m+1)
		{
			puts("NO");
			continue;
		}
		n+=m;
		for(i=2;i*i<=n;i++)if(n%i==0)break;
		if(i*i>n)puts("YES");
		else puts("NO");
	}
	return 0;
}