#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,d,h;
	scanf("%d%d%d",&n,&d,&h);
	int maxd=d-h;
	if (maxd>h||(n>2&&d==1))
	{
		printf("-1");
		return 0;
	}
	for (int i=1;i<=h;i++) printf("%d %d\n",i,i+1);
	if (maxd==0) for (int i=h+2;i<=n;i++) printf("%d %d\n",h,i);
	else
	{
		printf("1 %d\n",h+2);
		for (int i=1;i<maxd;i++) printf("%d %d\n",h+1+i,h+2+i);
		for (int i=h+2+maxd;i<=n;i++) printf("1 %d\n",i);
	}
	return 0;
}