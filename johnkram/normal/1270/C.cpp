#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1048576
ll s1;
int t,n,i,s2;
int A(int x)
{
	return x<0?-x:x;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		s1=s2=0;
		while(n--)
		{
			scanf("%d",&i);
			s1+=i;
			s2^=i;
		}
		printf("2\n%d %lld\n",s2,s1+s2);
	}
	return 0;
}