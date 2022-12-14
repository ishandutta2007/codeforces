#include <stdio.h>
#include <string.h>

char x[200010],y[200010];
int check[200010][30],check2[30];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	int b = strlen(x+1);
	for(int i=0;i<26;i++) for(int j=1;j<=b;j++) check[j][i] = check[j-1][i] + (x[j]=='a'+i?1:0);
	
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		scanf("%s",y+1);
		int d = strlen(y+1);
		for(int j=0;j<26;j++) check2[j] = 0;
		for(int j=1;j<=d;j++) check2[y[j]-'a']++;
		
		int min = 1, max = b;
		int ans = a;
		while(min<=max)
		{
			int h = (min+max)/2;
			for(int j=0;j<26;j++)
			{
				if(check[h][j]<check2[j])
				{
					min = h+1;
					goto u;
				}
			}
			ans = h;
			max = h-1;
			u:;
		}
		printf("%d\n",ans);
	}
}