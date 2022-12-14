#include <stdio.h>

int x[310];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int l = 1, r = a;
		while(l<=r)
		{
			printf("%d ",x[l]);
			l++;
			if(l>r) break;
			printf("%d ",x[r]);
			r--;
			if(l>r) break;
		}
		printf("\n");
	}
}