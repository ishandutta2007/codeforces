#include <stdio.h>
#define SIZE 350

int x[100010],right[100010],check[100010];
int next[100010][30];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) right[i] = a+1;
	for(int j=2;j<=100000;j++) check[j] = a+1;
	
	for(int i=a;i>=1;i--)
	{
		int c = x[i];
		for(int j=2;j<=SIZE;j++)
		{
			if(c%j==0)
			{
				right[i] = right[i]<check[j]?right[i]:check[j];
				while(c%j==0) c/=j;
				check[j] = i;
			}
		}
		if(c>1)
		{
			right[i] = right[i]<check[c]?right[i]:check[c];
			check[c] = i;
		}
	}
	right[a+1] = a+1;
	
	for(int i=a;i>=1;i--) right[i] = right[i]<right[i+1]?right[i]:right[i+1];
	for(int i=1;i<=a;i++) next[i][0] = right[i];
	next[a+1][0] = a+1;
	
	for(int j=1;j<=20;j++) for(int i=1;i<=a+1;i++) next[i][j] = next[next[i][j-1]][j-1];
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		int ans = 0;
		scanf("%d%d",&c,&d);
		for(int j=20;j>=0;j--)
		{
			if(next[c][j]<=d)
			{
				ans += (1<<j);
				c = next[c][j];
			}
		}
		if(c<=d) ans++;
		printf("%d\n",ans);
	}
}