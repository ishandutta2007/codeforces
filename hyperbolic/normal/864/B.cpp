#include <stdio.h>

char x[210];
char check[30];
int main()
{
	int a;
	int ans = 0;
	scanf("%d%s",&a,x+1);
	for(int i=1;i<=a;i++)
	{
		if('A'<=x[i]&&x[i]<='Z') continue;
		for(int j=0;j<=26;j++) check[j] = 0;
		check[x[i]-'a'+1] = 1;
		for(int j=i+1;j<=a;j++)
		{
			if('A'<=x[j]&&x[j]<='Z') break;
			if(check[x[j]-'a'+1]==0) check[x[j]-'a'+1] = 1;
		}
		
		int s = 0;
		for(int j=0;j<=26;j++) s+=check[j];
		ans = ans>s?ans:s;
	}
	printf("%d",ans);
}