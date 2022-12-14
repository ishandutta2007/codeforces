#include <stdio.h>

int count[6];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		count[0] = count[1] = count[2] = 0;
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			count[b%3]++;
		}
		int ans = 0;
		if(count[0]>(a/3)) ans += (count[0]-(a/3)), count[1] += (count[0]-(a/3)), count[0] = (a/3);
		if(count[1]>(a/3)) ans += (count[1]-(a/3)), count[2] += (count[1]-(a/3)), count[1] = (a/3);
		if(count[2]>(a/3)) ans += (count[2]-(a/3)), count[0] += (count[2]-(a/3)), count[2] = (a/3);
		if(count[0]>(a/3)) ans += (count[0]-(a/3)), count[1] += (count[0]-(a/3)), count[0] = (a/3);
		if(count[1]>(a/3)) ans += (count[1]-(a/3)), count[2] += (count[1]-(a/3)), count[1] = (a/3);
		if(count[2]>(a/3)) ans += (count[2]-(a/3)), count[0] += (count[2]-(a/3)), count[2] = (a/3);
		printf("%d\n",ans);
	}
}