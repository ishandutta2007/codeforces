#include <stdio.h>
#include <vector>

std::vector<int> V1,V2;
int main()
{
	int a;
	scanf("%d",&a);
	int count = 0;
	int s = 0 ,t = 0;
	int control = 0;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		if(control==1)
		{
			if(s!=b)
			{
				count++;
				s = b;
			}
			else
			{
				count++;
				t = b;
				control = 0;
			}
		}
		else
		{
			if(s==b)
			{
				if(t!=b)
				{
					count++;
					t = b;
				}
			}
			else
			{
				if(t==b)
				{
					count++;
					s = b;
				}
				else
				{
					if(s!=t) control = 1;
					s = b;
					count++;
				}
			}
		}
	}
	printf("%d",count);
}