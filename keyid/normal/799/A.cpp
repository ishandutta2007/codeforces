#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,t,k,d;
	scanf("%d%d%d%d",&n,&t,&k,&d);
	int tm=((n-1)/k+1)*t-1;
	if (d>=tm)
	{
		printf("NO");
		return 0;
	}
	int s1=tm/t*k,s2=(tm-d)/t*k;
	if (s1+s2>=n)
		printf("YES");
	else
		printf("NO");
	return 0;
}