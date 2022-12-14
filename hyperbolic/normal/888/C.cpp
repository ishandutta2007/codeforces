#include <stdio.h>
#include <string.h>

char x[100010];
int check[100010][30];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	
	int ans = a;
	int min = 1, max = a;
	while(min<=max)
	{
		int h = (min+max)/2;
		
		for(int j=0;j<26;j++) check[1][j] = 0;
		for(int i=1;i<=h;i++) check[1][x[i]-'a']++;
		
		for(int i=2;i+h-1<=a;i++)
		{
			for(int j=0;j<26;j++) check[i][j] = check[i-1][j];
			check[i][x[i-1]-'a']--;
			check[i][x[i+h-1]-'a']++;
		}
		
		for(int j=0;j<26;j++)
		{
			for(int i=1;i+h-1<=a;i++) if(check[i][j]==0) goto u;
			
			ans = h;
			max = h-1;
			goto v;
			
			u:;
		}
		min = h+1;
		v:;
	}
	printf("%d",ans);
}