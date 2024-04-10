#include <stdio.h>

int count[1010];
char x[1010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++) count[x[i]-'A']++;
	
	int s = 2*(count['L'-'A']<count['R'-'A']?count['L'-'A']:count['R'-'A']);
	int t = 2*(count['U'-'A']<count['D'-'A']?count['U'-'A']:count['D'-'A']);
	printf("%d",s+t);
}