#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,a;
	scanf("%d",&n);
	for (int i=1;i*i<=n;i++)
		if (n%i==0)
			a=i;
	printf("%d %d",a,n/a);
	return 0;
}