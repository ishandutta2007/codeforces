#include <stdio.h>
#include <vector>
#include <algorithm>

int power(int a, int b)
{
	int ans = 1;
	for(int i=1;i<=b;i++) ans*=a;
	return ans;
}

void func(long long int k, int d)
{
	std::vector<int> temp;
	while(k)
	{
		temp.push_back(k%10);
		k/=10;
	}
	while(temp.size()<d) temp.push_back(0);
	std::reverse(temp.begin(),temp.end());
	for(int i=0;i<temp.size();i++) printf("%d",temp[i]);
	
}

int x[110];
long long int y[110];

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		b++;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=1;i<a;i++)
		{
			int t = power(10,x[i+1]-x[i])-1<b?power(10,x[i+1]-x[i])-1:b;
			y[i] = t;
			b -= t;
		}
		
		int control = 0;
		if(b>0) printf("%lld",b), control = 1;
		for(int i=a-1;i>=1;i--)
		{
			if(control==0)
			{
				if(y[i]>0) printf("%lld",y[i]);
				else continue;
			}
			else func(y[i],x[i+1]-x[i]);
		}
		printf("\n");
	}
}