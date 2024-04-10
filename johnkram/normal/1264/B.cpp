#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
int a,b,c,d,n,s,t,i;
int main()
{
	cin>>a>>b>>c>>d;
	n=a+b+c+d;
	s=a+c;
	t=b+d;
	if(max(s-t,t-s)>1)
	{
		puts("NO");
		return 0;
	}
	if(a&&d>c)
	{
		puts("NO");
		return 0;
	}
	if(s<=t)
	{
		puts("YES");
		for(i=0;i<n;i++)if(!(i&1))if(d)
		{
			d--;
			printf("3 ");
		}
		else
		{
			b--;
			printf("1 ");
		}
		else if(c)
		{
			c--;
			printf("2 ");
		}
		else
		{
			a--;
			printf("0 ");
		}
		return 0;
	}
	if(c&&d==c)
	{
		puts("NO");
		return 0;
	}
	puts("YES");
	for(i=0;i<n;i++)if(i&1)if(d)
	{
		d--;
		printf("3 ");
	}
	else
	{
		b--;
		printf("1 ");
	}
	else if(c)
	{
		c--;
		printf("2 ");
	}
	else
	{
		a--;
		printf("0 ");
	}
	return 0;
}