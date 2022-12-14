#include <stdio.h>

char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		int count1 = 0, count2 = 0;
		for(int i=1;i<a;i++) if(x[i]=='1'&&x[i+1]=='1') count1++;
		for(int i=1;i<a;i++) if(x[i]=='0'&&x[i+1]=='0') count2++;
		printf("%d\n",count1>count2?count1:count2);
	}
}