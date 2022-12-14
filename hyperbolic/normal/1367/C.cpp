#include <stdio.h>

char x[200010];
int y[400010],z[400010],s1[400010],s2[400010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		for(int i=0;i<=b+a+1;i++) y[i] = z[i] = 0;
		for(int i=0;i<=b+a+1;i++) s1[i] = s2[i] = 0;
		
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='1')
			{
				y[i]++;
				y[i+b+1]--;
			}
		}
		for(int i=1;i<=a;i++) s1[i] = s1[i-1] + y[i];
		
		for(int i=a;i>=1;i--)
		{
			if(x[i]=='1')
			{
				z[b+i]++;
				z[b+i-b-1]--;
			}
		}
		for(int i=b+a;i>=b+1;i--) s2[i] = s2[i+1] + z[i];
		
		
		int ans = 0;
		int limit = 0;
		for(int i=1;i<=a;i++)
		{
			if(i<=limit) continue;
			if(s1[i]==0&&s2[b+i]==0)
			{
				ans++;
				limit = i+b;
			}
		}
		printf("%d\n",ans);
	}
}