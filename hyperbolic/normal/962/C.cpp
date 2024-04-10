#include <stdio.h>
#include <math.h>
#define MAX 1234567

int func(int a, int count, int check, int sum)
{
	if(count==0)
	{
		if(check==0) return MAX;
		
		int t = (int)sqrt(sum);
		if(t*t==sum || (t-1)*(t-1)==sum||(t+1)*(t+1)==sum) return 0;
		else return MAX;
	}
	
	int c = 1;
	for(int i=1;i<count;i++) c*=10;
	if((a/c)==0 && check==0) return func(a%c,count-1,check,sum)+1;
	else
	{
		int s1 = func(a%c,count-1,check,sum)+1;
		int s2 = func(a%c,count-1,1,10*sum+(a/c));
		return s1<s2?s1:s2;
	}
}

int main()
{
	int a;
	scanf("%d",&a);
	int b = a;
	int count = 0;
	while(b) b/=10,count++;
	int c = func(a,count,0,0);
	if(c>=count) printf("-1");
	else printf("%d",c);
}