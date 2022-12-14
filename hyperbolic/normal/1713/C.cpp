#include <stdio.h>

int x[100010],temp[100010];
void func(int k)
{
	if(k<=0) return;
	int p;
	for(int i=1;;i++)
	{
		if(i*i>=k)
		{
			p = i*i;
			break;
		}
	}
	
	int start = p - k;
	for(int i=start;i<=k;i++) temp[i] = x[i];
	for(int i=start;i<=k;i++) x[i] = temp[start+k-i];
	func(start-1);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=0;i<a;i++) x[i] = i;
		
		func(a-1);
		for(int i=0;i<a;i++) printf("%d ",x[i]);
		printf("\n");
	}
}