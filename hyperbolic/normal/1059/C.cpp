#include <stdio.h>

void func(int s, int t)
{
	if(s==0) return;
	if(s==3)
	{
		printf("%d %d %d",t,t,3*t);
		return;
	}
	int count = 0;
	for(int i=1;i<=s;i+=2) count++,printf("%d ",t);
	func(s-count,t*2);
}


int main()
{
	int a;
	scanf("%d",&a);
	func(a,1);
}