#include <stdio.h>
#include <vector>
#include <string.h>

char s[100010];
char t[10];
int x[30],y[30];
int main()
{
	int a,count=0;
	scanf("%d",&a);
	for(int i=0;i<26;i++) y[i] = 1;
	for(int i=1;i<a;i++)
	{
		scanf("%s%s",t+1,s+1);
		int b = strlen(s+1);
		int S = 0;
		for(int j=0;j<26;j++) x[j] = 0;
		for(int j=0;j<26;j++) S+=y[j];
		if(t[1]=='!')
		{
			if(S==1) count++;
			for(int j=1;j<=b;j++) x[s[j]-'a'] = 1;
			for(int j=0;j<26;j++) if(x[j]==0) y[j] = 0;
		}
		else if(t[1]=='.')
		{
			for(int j=1;j<=b;j++) x[s[j]-'a'] = 1;
			for(int j=0;j<26;j++) if(x[j]==1) y[j] = 0;
		}
		else
		{
			if(S==1)
			{
				if(y[s[1]-'a']==0) count++;
			}
			else y[s[1]-'a'] = 0;
		}
	}
	printf("%d",count);
}