#include <stdio.h>
#include <string.h>

char x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	
	int count = 0;
	for(int i=1;i<=a;i++) if(x[i]=='8') count++;
	
	int ans = 0;
	for(int i=0;i<=count;i++)
	{
		if(a-i>=10*i) ans = i;
	}
	printf("%d",ans);
}