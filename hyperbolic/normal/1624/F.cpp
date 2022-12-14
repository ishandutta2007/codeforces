#include <stdio.h>

int getQuery(int k)
{
	printf("+ %d\n",k);
	fflush(stdout);
	
	int a;
	scanf("%d",&a);
	return a;
}

int main()
{
	int a;
	scanf("%d",&a);
	int s1 = 0; // x+1 = s1b + s2
	int l = 0, r = a-1;
	int sum = 0;
	while(l<r)
	{
		int h = (l+r+1)/2;
		int t = a-(h+sum)%a;
		
		if(t<a)
		{
			sum += t;
			int s2 = getQuery(t);
			if(s2!=s1)
			{
				s1 = s2;
				l = h;
			}
			else r = h-1;
		}
		else l = h;
	}
	printf("! %d",l+sum);
	fflush(stdout);
	
}