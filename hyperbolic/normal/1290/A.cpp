#include <stdio.h>

int x[5010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		if(c>b-1) c = b-1;
		
		int ans = -1234567890;
		for(int i=1;i<=c+1;i++)
		{
			int min = 1234567890;
			for(int j=0;j<=b-c-1;j++)
			{
				int L = i+j, R = i+(a-c-1)-(b-c-1-j);
				int k = x[L]>x[R]?x[L]:x[R];
				min = min<k?min:k;
			}
			ans = ans>min?ans:min;
		}
		printf("%d\n",ans);
	}
}