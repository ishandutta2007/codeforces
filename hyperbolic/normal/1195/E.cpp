#include <stdio.h>
#include <deque>
#include <vector>
#include <algorithm>


std::deque<long long int> D;
long long int x[3010][3010];
long long int y[3010][3010];

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	long long int e,f,g,h;
	scanf("%lld%lld%lld%lld",&e,&f,&g,&h);
	
	int s = 1, t = 1;
	for(int i=1;i<=a*b;i++)
	{
		if(t>b) s++, t = 1;
		x[s][t] = e;
		e = (e*f+g)%h;
		t++;
	}
	
	for(int j=1;j<=b;j++)
	{
		while(!D.empty()) D.pop_back();
		for(int i=1;i<=c;i++)
		{
			while(!D.empty() && D.back()>=x[i][j]) D.pop_back();
			D.push_back(x[i][j]);
		}
		y[1][j] = D.front();
		for(int i=2;i<=a-c+1;i++)
		{
			if(!D.empty() && D.front()==x[i-1][j]) D.pop_front();
			while(!D.empty() && D.back()>=x[i+c-1][j]) D.pop_back();
			D.push_back(x[i+c-1][j]);
			y[i][j] = D.front();
		}
	}
	
	long long int ans = 0;
	for(int i=1;i<=a-c+1;i++)
	{
		while(!D.empty()) D.pop_back();
		for(int j=1;j<=d;j++)
		{
			while(!D.empty() && D.back()>=y[i][j]) D.pop_back();
			D.push_back(y[i][j]);
		}
		ans += D.front();
		for(int j=2;j<=b-d+1;j++)
		{
			if(!D.empty()&&D.front()==y[i][j-1]) D.pop_front();
			while(!D.empty() && D.back()>=y[i][j+d-1]) D.pop_back();
			D.push_back(y[i][j+d-1]);
			ans += D.front();
		}
	}
	printf("%lld",ans);
}