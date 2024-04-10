#include <stdio.h>

int x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		for(int j=1;j<=b;j++)
		{
			int min = 1, max = 1;
			for(int i=2;i<=a;i++) if(x[min]>x[i]) min = i;
			for(int i=2;i<=a;i++) if(y[max]<y[i]) max = i;
			if(x[min]>=y[max]) break;
			else
			{
				int temp = x[min];
				x[min] = y[max];
				y[max] = temp;
			}
		}
		int ans = 0;
		for(int i=1;i<=a;i++) ans += x[i];
		printf("%d\n",ans);
	}
}