#include <stdio.h>
#include <algorithm>
#define MOD 998244353

bool cmp1(std::pair<int,int> a, std::pair<int,int> b)
{
	return a.first<b.first;
}
bool cmp2(std::pair<int,int> a, std::pair<int,int> b)
{
	return a.second<b.second;
}

std::pair<int,int> x[300010];
long long int fact[300010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=300000;i++) fact[i] = fact[i-1]*i, fact[i]%=MOD;
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		x[i]=std::make_pair(b,c);
	}
	
	long long int s1=1,s2=1,s3=1;
	std::sort(x+1,x+a+1,cmp1);
	int pivot = 1;
	for(int i=2;i<=a;i++)
	{
		if(x[i].first!=x[i-1].first)
		{
			s1 *= fact[i-pivot], s1%=MOD;
			pivot = i;
		}
	}
	s1*=fact[a-pivot+1], s1%=MOD;
	
	std::sort(x+1,x+a+1,cmp2);
	pivot = 1;
	for(int i=2;i<=a;i++)
	{
		if(x[i].second!=x[i-1].second)
		{
			s2 *= fact[i-pivot], s2%= MOD;
			
			std::sort(x+pivot,x+i,cmp1);
			if(x[pivot-1].first>x[pivot].first) s3 = 0;
			long long int s = 1;
			for(int j=pivot+1;j<i;j++)
			{
				if(x[j].first!=x[j-1].first)
				{
					s3 *= fact[s], s3%=MOD;
					s = 1;
				}
				else s++;
			}
			s3 *= fact[s], s3%=MOD;
			pivot = i;
		}
	}
	s2 *= fact[a-pivot+1], s2%=MOD;
	
	std::sort(x+pivot,x+a+1,cmp1);
	if(x[pivot-1].first>x[pivot].first) s3 = 0;
	long long int s = 1;
	for(int j=pivot+1;j<=a;j++)
	{
		if(x[j].first!=x[j-1].first)
		{
			s3 *= fact[s], s3%=MOD;
			s = 1;
		}
		else s++;
	}
	s3 *= fact[s], s3%=MOD;
	
	printf("%lld",(fact[a]-s1-s2+s3+2*MOD)%MOD);
	
}