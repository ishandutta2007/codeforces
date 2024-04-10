#include <stdio.h>
#include <string.h>

int check[110];
char x[200010];
int main()
{
	scanf("%s",x+1);
	x[0] = 'a';
	
	int a = strlen(x+1);
	
	int count = 1;
	int ans = 0;
	for(int i=2;i<=a+1;i++)
	{
		if(x[i]!=x[i-1])
		{
			for(int j=i-2;j>=i-count;j-=2)
			{
				check[0] = check[1] = check[2] = 0;
				check[x[j-1]-'a'] = 1;
				check[x[j+1]-'a'] = 1;
				for(int k=0;k<=2;k++) if(check[k]==0) x[j] = k+'a';
			}
			ans += count/2;
			count = 1;
		}
		else count++;
	}
	
	for(int i=1;i<=a;i++) printf("%c",x[i]);
}