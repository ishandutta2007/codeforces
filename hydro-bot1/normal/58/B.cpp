// Hydro submission #63454e8c8d8541e88933991e@1665486476454
#include<cstdio>
using namespace std;
int main()
{
	int n,x=2;
	scanf("%d",&n);
	while(n>1)
	{
		if(n%x!=0)x++;
		else
		{
			printf("%d ",n);
			n=n/x;
		}
	}
	printf("1\n");
	return 0;
}