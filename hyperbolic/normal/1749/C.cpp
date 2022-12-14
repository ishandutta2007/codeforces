#include <stdio.h>
#include <algorithm>

int x[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			int R = a, L = 1;
			for(int j=1;j<=i;j++)
			{
				while(R>=1 && x[R]>i-j+1) R--;
				if(R<L) goto u;
				R--;
				L++;
			}
			ans = i;
		}
		u:;
		printf("%d\n",ans);
	}
}