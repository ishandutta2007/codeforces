#include <stdio.h>
#include <vector>

std::vector<int> V;
int ans = 1;
int main()
{
	int a;
	scanf("%d",&a);
	if(a==1)
	{
		printf("1 0");
		return 0;
	}
	int b = a;
	for(int i=2;i*i<=a;i++)
	{
		int count = 0;
		while(b%i==0)
		{
			count++;
			b/=i;
		}
		if(count>=1) ans *= i;
		if(count>=1) V.push_back(count);
	}
	if(b>1) V.push_back(1);
	if(b>1) ans *= b;
	
	int max = 0;
	for(int i=0;i<V.size();i++) max = max>V[i]?max:V[i];
	
	int C = 0;
	int D = 0;
	for(int i=0;i<30;i++)
	{
		if((1<<i)==max)
		{
			C = i;
			D = 0;
			break;
		}
		else if((1<<i)>max)
		{
			C = i;
			D = 1;
			break;
		}
	}
	for(int i=0;i<V.size();i++)
	{
		if(max!=V[i])
		{
			printf("%d %d",ans,C+1);
			return 0;
		}
	}
	printf("%d %d",ans,C+D);
}