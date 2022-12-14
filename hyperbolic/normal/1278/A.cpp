#include <stdio.h>
#include <string.h>

char x[100010],y[100010];
int check[30],check2[30];
int main()
{
	int a;
	scanf("%d",&a);
	for(int k=1;k<=a;k++)
	{
		scanf("%s%s",x+1,y+1);
		int b = strlen(x+1), c = strlen(y+1);
		if(c<b)
		{
			printf("NO\n");
			continue;
		}
		else
		{
			for(int i=0;i<=26;i++) check2[i] = 0;
			for(int i=1;i<=b;i++) check2[x[i]-'a']++;
			
			for(int i=1;i+(b-1)<=c;i++)
			{
				for(int j=0;j<=26;j++) check[j] = 0;
				for(int j=i;j<=i+(b-1);j++) check[y[j]-'a']++;
				for(int j=0;j<=25;j++) if(check[j]!=check2[j]) goto u;
				printf("YES\n");
				goto v;
				
				u:;
			}
			printf("NO\n");
			v:;
		}
	}
}