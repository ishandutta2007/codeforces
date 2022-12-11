#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

int main()
{
	//freopen("read.txt","r",stdin);
	int a,b;
	scanf("%d%d",&a,&b);
	if (a<b)
	{
		printf("-1");
		return 0;
	}
	int t=(a-b)/(2*b);
	printf("%.10Lf",(ld)(a+b)/(2*t+2));
	return 0;
}