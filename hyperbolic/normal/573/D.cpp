#include <stdio.h>
#include <algorithm>
std::pair<long long int,int> x[30010],y[30010];
int target[30010];
long long int DP[30010];
long long int MIN = -1;
long long int type1[30010],type2[30010],type3[30010],type4[30010];

int main()
{
	for(int i=1;i<=17;i++) MIN*=10;
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i].first);
	for(int i=1;i<=a;i++) scanf("%lld",&y[i].first);
	for(int i=1;i<=a;i++) x[i].second = y[i].second = i;
	std::sort(x+1,x+a+1);
	std::sort(y+1,y+a+1);
	for(int i=1;i<=a;i++) target[y[i].second] = i;
	
	for(int i=1;i<=a;i++) type1[i] = x[i].first*y[i].first;
	for(int i=2;i<=a;i++) type2[i] = x[i-1].first*y[i].first + x[i].first*y[i-1].first;
	for(int i=3;i<=a;i++) type3[i] = x[i].first*y[i-2].first + x[i-1].first*y[i].first + x[i-2].first*y[i-1].first;
	for(int i=3;i<=a;i++) type4[i] = x[i-2].first*y[i].first + x[i-1].first*y[i-2].first + x[i].first*y[i-1].first;
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		int s = target[c];
		int t = target[d];
		int k = y[s].second;
		y[s].second = y[t].second;
		y[t].second = k;
		target[y[s].second] = s;
		target[y[t].second] = t;
		
		DP[0] = DP[1] = MIN;
		DP[2] = 0;
		for(int j=1;j<=a;j++)
		{
			int t = j+2;
			
			if(x[j].second==y[j].second)
			{
				if(j<=1)
				{
					DP[t] = MIN;
					continue;
				}
				DP[t] = DP[t-2] + type2[j];
				
				if(j<=2) continue;
				if(x[j-2].second==y[j-2].second)
				{
					long long int s2 = DP[t-3] + type3[j];
					long long int s3 = DP[t-3] + type4[j];
					DP[t] = DP[t]>s2?DP[t]:s2;
					DP[t] = DP[t]>s3?DP[t]:s3;
				}
			}
			else
			{
				DP[t] = DP[t-1] + type1[j];
				if(j<=1) continue;
				if(x[j-1].second==y[j-1].second)
				{
					long long int s2 = DP[t-2] + type2[j];
					DP[t] = DP[t]>s2?DP[t]:s2;
				}
			}
		}
		printf("%lld\n",DP[a+2]);
	}
}