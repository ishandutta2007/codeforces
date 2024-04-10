#include <stdio.h>
#include <string.h>

char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		
		int count0 = 0, count1 = 0;
		for(int i=1;i<=a;i++) if(x[i]=='0') count0++;
		for(int i=1;i<=a;i++) if(x[i]=='1') count1++;
		if(count0==0) printf("0\n");
		else
		{
			int C = 0;
			for(int i=1;i<=a;i++) if(x[i]=='0'&&x[i-1]!='0') C++;
			if(C==1) printf("1\n");
			else printf("2\n");
		}
	}
}