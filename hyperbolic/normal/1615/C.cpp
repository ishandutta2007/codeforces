#include <stdio.h>
#define MAX 12345678

char x[100010],y[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s%s",x+1,y+1);
		for(int i=1;i<=a;i++) x[i] -= '0', y[i] -= '0';
		
		int count1 = 0, count2 = 0, count3 = 0 , count4 = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]==1&&y[i]==1) count1++;
			if(x[i]==1&&y[i]==0) count2++;
			if(x[i]==0&&y[i]==1) count3++;
			if(x[i]==0&&y[i]==0) count4++;
		}
		
		int ans = MAX;
		if(count2==count3) ans = ans<2*count2?ans:2*count2;
		if(count1>0 && count4==count1-1) ans = ans<2*count4+1?ans:2*count4+1;
		if(count2>0 && count1==count4+1) ans = ans<2*count1+1?ans:2*count1+1;
		if(ans==MAX) printf("-1\n");
		else printf("%d\n",ans);
	}
}