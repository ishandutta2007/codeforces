#include <stdio.h>
#include <algorithm>

std::pair<int,int> x[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		x[i]=std::make_pair(c,d);
	}
	for(int i=1;i<=a;i++) printf("%d",i%2);
}