#include <stdio.h>
char x1[110],y1[110];
char x[10][10],y[10][10];
char s1[110],s2[110];
int main()
{
	int s;
	int i,j;
	scanf("%s%s",x[1]+1,x[2]+1);
	scanf("%s%s",y[1]+1,y[2]+1);
	
	x1[1] = x[1][1];
	x1[2] = x[1][2];
	x1[3] = x[2][2];
	x1[4] = x[2][1];
	
	y1[1] = y[1][1];
	y1[2] = y[1][2];
	y1[3] = y[2][2];
	y1[4] = y[2][1];
	
	for(i=5;i<=8;i++) x1[i] = x1[i-4];
	for(i=1,s=1;i<=8;i++)
	{
		if(x1[i]=='X') continue;
		s1[s++] = x1[i];
	}
	for(i=1,s=1;i<=4;i++)
	{
		if(y1[i]=='X') continue;
		s2[s++] = y1[i];
	}
	for(i=1;i<=3;i++)
	{
		for(j=1;j<=3;j++)
		{
			if(s1[i+j-1]!=s2[j]) break;
		}
		if(j>3)
		{
			printf("YES");
			return 0;
		}
	}
	printf("NO");
}