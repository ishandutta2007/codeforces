#include <stdio.h>
#include <map>

std::map<int,int> M;
int main()
{
	int a;
	scanf("%d",&a);
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		M[b]++;
		ans = ans>M[b]?ans:M[b];
	}
	printf("%d",ans);
}