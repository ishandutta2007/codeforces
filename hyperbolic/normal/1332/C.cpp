#include <stdio.h>

char x[200010];
int check[30];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int ans = 0;
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		for(int i=1;i<=b/2;i++)
		{
			for(int j=0;j<26;j++) check[j] = 0;
			for(int j=i;j<=a;j+=b) check[x[j]-'a']++;
			for(int j=b-i+1;j<=a;j+=b) check[x[j]-'a']++;
			
			int s = 0, m = 0;
			for(int j=0;j<26;j++)
			{
				s += check[j];
				m = m>check[j]?m:check[j];
			}
			ans += (s-m);
		}
		if(b%2==1)
		{
			for(int j=0;j<26;j++) check[j] = 0;
			for(int j=(b+1)/2;j<=a;j+=b) check[x[j]-'a']++;
			
			int s = 0, m = 0;
			for(int j=0;j<26;j++)
			{
				s += check[j];
				m = m>check[j]?m:check[j];
			}
			ans += (s-m);
		}
		printf("%d\n",ans);
	}
}