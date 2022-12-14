#include <stdio.h>
#include <algorithm>

std::pair<int,int> x[110];
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=1;i<=a;i++)
	{
		int d,e;
		scanf("%d%d",&d,&e);
		x[i]=std::make_pair(d,e);
	}
	
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=i+1;j<=a;j++)
		{
			int s1 = x[i].first, s2 = x[i].second;
			int t1 = x[j].first, t2 = x[j].second;
			long long int val = 0;
			if(s1+t1<=b && s2<=c && t2<=c) val = s1*s2 + t1*t2;
			if(s1+t1<=c && s2<=b && t2<=b) val = s1*s2 + t1*t2;
			if(s2+t2<=b && s1<=c && t1<=c) val = s1*s2 + t1*t2;
			if(s2+t2<=c && s1<=b && t1<=b) val = s1*s2 + t1*t2;
			if(s1+t2<=b && s2<=c && t1<=c) val = s1*s2 + t1*t2;
			if(s1+t2<=c && s2<=b && t1<=b) val = s1*s2 + t1*t2;
			if(s2+t1<=b && s1<=c && t2<=c) val = s1*s2 + t1*t2;
			if(s2+t1<=c && s1<=b && t2<=b) val = s1*s2 + t1*t2; 
			ans = ans>val?ans:val;
		}
	}
	printf("%d",ans);
}