#include <stdio.h>

int count[1010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int ans = 0;
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		count[c]++;
		int control = 1;
		for(int j=1;j<=a;j++) if(count[j]==0) control = 0;
		if(control)
		{
			for(int j=1;j<=a;j++) count[j]--;
			ans++;
		}
	}
	printf("%d",ans);
}