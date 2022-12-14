#include <stdio.h>
#include <vector>

int a,b,MAX;
std::vector< std::pair<int,int> > temp;
int check[2010][2010];
long long int getSum(int k)
{
	temp.clear();
	int s = k;
	int t = (k+b)%2;
	long long int ans = 0;
	while(t<=MAX)
	{
		if(check[s][t]==0)
		{
			for(int j=temp.size();j>=0;j-=2) ans += j;
			temp.clear();
			if(s==k) t+=2;
			else s--,t++;
		}
		else
		{
			temp.push_back(std::make_pair(s,t));
			if(s==k) s++, t++;
			else s--,t++;
		}
	}
	
	temp.clear();
	s = k, t = (k+b)%2;
	while(t<=MAX)
	{
		if(check[s][t]==0)
		{
			for(int j=temp.size();j>=0;j-=2) ans += j;
			temp.clear();
			if(s==k) t+=2;
			else s++,t++;
		}
		else
		{
			temp.push_back(std::make_pair(s,t));
			if(s==k) s--, t++;
			else s++,t++;
		}
	}
	return ans;
}

int main()
{
	int c;
	scanf("%d%d%d",&a,&b,&c);
	MAX = a+b+2;
	
	for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) check[i-j+b][i+j] = 1;
	int C = a*b;
	long long int ans = 0;
	for(int i=1;i<=a+b;i++) ans += getSum(i);
	
	while(c--)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		int t = d-e+b;
		ans -= getSum(t-1);
		ans -= getSum(t);
		ans -= getSum(t+1);
		if(check[d-e+b][d+e]==1)
		{
			C--;
			check[d-e+b][d+e]=0;
		}
		else
		{
			C++;
			check[d-e+b][d+e]=1;
		}
		ans += getSum(t-1);
		ans += getSum(t);
		ans += getSum(t+1);
		printf("%lld\n",ans-C);
	}
}