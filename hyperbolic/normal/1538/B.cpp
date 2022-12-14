#include <stdio.h>

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		if(sum%a!=0) printf("-1\n");
		else
		{
			int ans = 0;
			for(int i=1;i<=a;i++) if(x[i]>(sum/a)) ans++;
			printf("%d\n",ans);
		}
	}
}