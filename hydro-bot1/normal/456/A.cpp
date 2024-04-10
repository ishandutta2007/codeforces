// Hydro submission #62d94f5325d42d05161bf2bc@1658408787488
#include <bits/stdc++.h>
using namespace std;
int n;
struct laptop{
	int a;
	int b;
};
int main()
{
	scanf("%d",&n);
	laptop x[n+10];
	for(int i=1;i<=n;i++)
	{
		cin>>x[i].a>>x[i].b;
	}
	for(int i=1;i<=n;i++)
	{
		if(x[i].a<x[i].b)
		{
			printf("Happy Alex\n");
			return 0;
		}
		else continue;
	}
	printf("Poor Alex\n");
	return 0;
}