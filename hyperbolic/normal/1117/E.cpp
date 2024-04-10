#include <stdio.h>
#include <string.h>


char x[10010];
char y1[10010],y2[10010],y3[10010];
char z1[10010],z2[10010],z3[10010];
int move[10010];
char ans[10010];

int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++)
	{
		int t = i;
		int s1 = t%26; t/= 26;
		int s2 = t%26; t/= 26;
		int s3 = t%26;
		y1[i] = s1+'a', y2[i] = s2+'a', y3[i] = s3+'a';
	}
	
	printf("? %s\n",y1+1);
	fflush(stdout);
	scanf("%s",z1+1);
	
	printf("? %s\n",y2+1);
	fflush(stdout);
	scanf("%s",z2+1);
	
	printf("? %s\n",y3+1);
	fflush(stdout);
	scanf("%s",z3+1);
	
	for(int i=1;i<=a;i++)
	{
		int s1 = z1[i]-'a';
		int s2 = z2[i]-'a';
		int s3 = z3[i]-'a';
		int t = s1+26*s2+26*26*s3;
		move[t] = i;
	}
	for(int i=1;i<=a;i++) ans[i] = x[move[i]];
	printf("! %s",ans+1);
	fflush(stdout);
}