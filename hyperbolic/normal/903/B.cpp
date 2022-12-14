#include <stdio.h>

int main()
{
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	int t = (d-1)/b;
	int h = t*e+1;
	int s;
	if(h<=a) s = 0;
	else s = (h-a-1)/(c-e)+1;
	printf("%d\n",s+t+1);
	for(int i=1;i<=s;i++) printf("HEAL\n");
	for(int i=1;i<=t+1;i++) printf("STRIKE\n");
}