#include <stdio.h>
#include <vector>
#include <algorithm>
#define SIZE1 200
#define SIZE2 500

int x[100010];
std::vector<long long int> V;
int count[200010];
int abs(int k)
{
	return k>0?k:-k;
}

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int ans = 1;
	for(int i=0;i<=SIZE1;i++)
	{
		V.clear();
		for(int j=1;j<=a;j++)
		{
			long long int val = x[j] - (long long int)i*j;
			V.push_back(val);
		}
		std::sort(V.begin(),V.end());
		int S = 1;
		for(int i=1;i<V.size();i++)
		{
			if(V[i]!=V[i-1]) S = 1;
			else S++;
			ans = ans>S?ans:S;
		}
	}
	for(int i=0;i>=-SIZE1;i--)
	{
		V.clear();
		for(int j=1;j<=a;j++)
		{
			long long int val = x[j] - (long long int)i*j;
			V.push_back(val);
		}
		std::sort(V.begin(),V.end());
		int S = 1;
		for(int i=1;i<V.size();i++)
		{
			if(V[i]!=V[i-1]) S = 1;
			else S++;
			ans = ans>S?ans:S;
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=i+SIZE2&&j<=a;j++)
		{
			if(abs(x[i]-x[j])%(j-i)==0)
			{
				int t = (x[j]-x[i])/(j-i)+100000;
				count[t]++;
				ans = ans>count[t]+1?ans:count[t]+1;
			}
		}
		for(int j=i+1;j<=i+SIZE2&&j<=a;j++)
		{
			if(abs(x[i]-x[j])%(j-i)==0)
			{
				int t = (x[j]-x[i])/(j-i)+100000;
				count[t]--;
			}
		}
	}
	printf("%d",a-ans);
}