#include <stdio.h>

int x[100010],y[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%1d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%1d",&y[i]);
	
	long long int count1 = 0, count2 = 0, count3 = 0 ,count4 = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]==1&&y[i]==1) count1++;
		if(x[i]==1&&y[i]==0) count2++;
		if(x[i]==0&&y[i]==1) count3++;
		if(x[i]==0&&y[i]==0) count4++;
	}
	long long int s = 0;
	s += count1*count4;
	s += count2*count3;
	s += count2*count4;
	printf("%lld",s);
}