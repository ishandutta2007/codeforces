#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	puts("YES");
	while (n--)
	{
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		int k1=x1%2?1:0,k2=y1%2?1:0;
		printf("%d\n",k1*2+k2+1);
	}
	return 0;
}