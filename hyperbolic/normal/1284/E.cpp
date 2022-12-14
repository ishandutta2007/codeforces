#include <stdio.h>
#include <vector>
#include <algorithm>

int SCC(std::pair<long long int,long long int> P1, std::pair<long long int,long long int> P2, std::pair<long long int,long long int> P3)
{
	long long int s1 = P1.first*P2.second + P2.first*P3.second + P3.first*P1.second;
	long long int s2 = P1.second*P2.first + P2.second*P3.first + P3.second*P1.first;
	return s1<s2?1:0;
}

std::pair<long long int, long long int> P[10010],P2[10010];
bool cmp(std::pair<long long int,long long int> P1,std::pair<long long int,long long int> P2)
{
	if(SCC(P[2],P[1],P1)==1 && SCC(P[2],P[1],P2)==0) return true;
	else if(SCC(P[2],P[1],P1)==0 && SCC(P[2],P[1],P2)==1) return false;
	else
	{
		if(SCC(P1,P[1],P2)==1) return true;
		else return false;
	}
}


int start[10010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		P[i] = std::make_pair(b,c);
		P2[i] = std::make_pair(b,c);
	}
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(P2[i]==P[j])
			{
				std::pair<long long int, long long int> temp = P[1];
				P[1] = P[j];
				P[j] = temp;
				std::sort(P+3,P+a+1,cmp);
				break;
			}
		}
		
		for(int j=a+1;j<=a+(a-1);j++) P[j] = P[j-a+1];
		
		ans += (long long int)(a-1)*(a-2)*(a-3)*(a-4)/24;
		start[1] = 2;
		for(int j=2;j<=a;j++)
		{
			start[j] = start[j-1];
			if(start[j]==j) start[j]++;
			while(1)
			{
				if(start[j]==j+(a-1)) break;
				if(SCC(P[j],P[1],P[start[j]])==1) start[j]++;
				else break;
			}
			
			long long int s1 = (start[j]-1-(j+1)+1);
			ans -= s1*(s1-1)*(s1-2)/6;
		}
	}
	printf("%lld",ans);
}