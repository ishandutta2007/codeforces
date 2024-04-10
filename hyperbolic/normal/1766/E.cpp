#include <stdio.h>
#include <vector>
#include <algorithm>

int x[300010];
int main()
{
	int a;
	scanf("%d",&a);
	long long int ans = 0;
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=1;i<=a;i++)
	{
		if(x[i]==0)
		{
			ans += (long long int)i*(a-i+1);
		}
	}
	
	long long int prev = 0;
	int last1 = -1, last2 = -1;
	std::pair<int,int> P1 = std::make_pair(-1,a+1), P2 = std::make_pair(-1,a+1);
	for(int i=a;i>=1;i--)
	{
		if(x[i]==0);
		else if(x[i]==3) prev += (P1.second-i);
		else if(P1.first==3 || x[i]==P1.first) prev += (P1.second-i);
		else
		{
			if(P1.first==2&&x[i]==1)
			{
				//321
				if(last1==-1) prev = (P1.second-i) + (a-P1.second+1)*2;
				else prev = (P1.second-i) + (last1-P1.second)*2 + (a-last1+1)*3;
			}
			else
			{
				//312
				if(last2==-1) prev = (P1.second-i) + (a-P1.second+1)*2;
				else prev = (P1.second-i) + (last2-P1.second)*2 + (a-last2+1)*3;
			}
		}
		ans += prev;
		
		if(x[i]==3 && P1.first==2 && P2.first==1) last1 = P2.second;
		if(x[i]==3 && P1.first==1 && P2.first==2) last2 = P2.second;
		if(x[i]>0)
		{
			if(x[i]==P1.first) P1.second = i;
			else
			{
				P2 = P1;
				P1 = std::make_pair(x[i],i);
			}
		}
	}
	printf("%lld",ans);
}