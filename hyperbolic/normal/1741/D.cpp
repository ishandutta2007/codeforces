#include <stdio.h>

int x[300010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=0;i<a;i++) scanf("%d",&x[i]);
		for(int i=0;i<a;i++) x[i]--;
		
		int ans = 0;
		for(int i=1;i<=a;i*=2)
		{
			for(int j=0;j<a;j+=i)
			{
				int L = j, R = j+i-1;
				int min = a+1, max = -1;
				for(int k=L;k<=R;k++)
				{
					min = min<x[k]?min:x[k];
					max = max>x[k]?max:x[k];
				}
				if(max-min+1==i)
				{
					int val1 = (min/i)%2;
					int val2 = (j/i)%2;
					if(val1!=val2) ans++;
				}
				else
				{
					printf("-1\n");
					goto u;
				}
			}
		}
		printf("%d\n",ans/2);
		u:;
	}
}