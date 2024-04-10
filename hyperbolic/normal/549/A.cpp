#include <stdio.h>
#include <algorithm>
char s[10];
char x[110][110];
int main()
{
	int a,b,i,j,count=0;
	scanf("%d%d",&a,&b);
	for(i=1;i<=a;i++)
	{
		scanf("%s",x[i]+1);
	}
	for(i=1;i<a;i++)
	{
		for(j=1;j<b;j++)
		{
			s[1] = x[i][j];
			s[2] = x[i+1][j];
			s[3] = x[i][j+1];
			s[4] = x[i+1][j+1];
			std::sort(s+1,s+5);
			if(s[1]=='a' && s[2]=='c' && s[3] == 'e' && s[4] =='f')
			{
				count++;
			}
		}
	}
	printf("%d",count);
}