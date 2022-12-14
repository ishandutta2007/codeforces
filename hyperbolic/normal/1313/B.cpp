#include <stdio.h>

int func(int a, int s, int t)
{
	// 1 ~ s-1 / t+2 ~ a
	// s+2 ~ a / 1 ~ t-1
	int count1, count2; // s+t-a+1~s-1 t+2~a
	if(s-1 <= a-t-1)
	{
		if(t-1 <= a-s-1) return 1;
		else return 1 + (s+t-a);
	}
	else
	{
		if(t-1 <= a-s-1) return 1 + (s+t-a);
		else return 1 + (s+t-a);
	}
	
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		
		int s1,s2;
		if(b+c<=a) s1 = 1;
		else s1 = 1+b+c-a;
		if(s1>a) s1 = a;
		
		if(b+c>=a+1) s2 = a;
		else s2 = b+c-1;
		printf("%d %d\n",s1,s2);
	}
}