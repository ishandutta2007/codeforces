#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		
		int L = b, R = b;
		for(int i=1;i<=c;i++)
		{
			int d,e;
			scanf("%d%d",&d,&e);
			if(R<d) continue;
			if(e<L) continue;
			
			L = L<d?L:d;
			R = R>e?R:e;
		}
		printf("%d\n",R-L+1);
	}
}