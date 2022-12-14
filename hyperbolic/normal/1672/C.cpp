#include <stdio.h>
#define MAX 12345678

int a;
int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int L = MAX, R = MAX;
		for(int i=1;i<a;i++)
		{
			if(x[i]==x[i+1])
			{
				L = i+1;
				break;
			}
		}
		for(int i=a;i>=2;i--)
		{
			if(x[i]==x[i-1])
			{
				R = i-1;
				break;
			}
		}
		if(L==MAX&&R==MAX) printf("0\n");
		else if(R<L) printf("0\n");
		else if(R==L) printf("1\n");
		else printf("%d\n",R-L);
	}
}