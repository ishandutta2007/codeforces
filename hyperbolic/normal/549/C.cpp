#include <stdio.h>

int main()
{
	int a,b,c,i,odd=0,even=0;
	scanf("%d%d",&a,&b);
	for(i=1;i<=a;i++)
	{
		scanf("%d",&c);
		if(c%2==1) odd++;
		if(c%2==0) even++;
	}
	if(a==b)
	{
		if(odd%2==1)
		{
			//win
			printf("Stannis");
			return 0;
		}
		else
		{
			//lose
			printf("Daenerys");
			return 0;
		}
	}
	if((a-b)%2==0)
	{
		if(b%2==0)
		{
			//lose
			printf("Daenerys");
			return 0;
		}
		else
		{
			if(even<=(a-b)/2)
			{
				//win
				printf("Stannis");
				return 0;
			}
			else
			{
				//lose
				printf("Daenerys");
				return 0;
			}
		}
	}
	else
	{
		if(b%2==0)
		{
			if(even>(a-b-1)/2 && odd>(a-b-1)/2)
			{
				//win
				printf("Stannis");
				return 0;
			}
			else
			{
				//lose
				printf("Daenerys");
				return 0;
			}
		}
		else
		{
			if(odd>(a-b-1)/2)
			{
				//win
				printf("Stannis");
				return 0;
			}
			else
			{
				//lose
				printf("Daenerys");
				return 0;
			}
		}
	}
}