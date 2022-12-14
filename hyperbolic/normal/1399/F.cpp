#include <stdio.h>
#include <algorithm>

std::pair<int,int> P[3010];
bool cmp(std::pair<int,int> A, std::pair<int,int> B)
{
	if(A.first==B.first) return A.second>B.second;
	return A.first<B.first;
}

int a;
int next[3010];
int check[3010][3010];
int func(int s, int t)
{
	if(s>a) return 0;
	
	if(check[s][t]!=-1) return check[s][t];
	
	if(P[s].second>P[t].second) return check[s][t] = func(s+1,t);
	else
	{
		int s1 = func(s+1,s) + func(next[s],t) + 1;
		int s2 = func(s+1,t);
		return check[s][t] = s1>s2?s1:s2;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=0;i<=a+1;i++) for(int j=0;j<=a+1;j++) check[i][j] = -1;
		
		for(int i=1;i<=a;i++)
		{
			int b,c;
			scanf("%d%d",&b,&c);
			P[i]=std::make_pair(b,c);
		}
		std::sort(P+1,P+a+1,cmp);
		P[0] = std::make_pair(-1,12345678);
		P[a+1] = std::make_pair(12345678,12345678);
		for(int i=1;i<=a;i++)
		{
			for(int j=i+1;j<=a+1;j++)
			{
				if(P[j].first>P[i].second)
				{
					next[i] = j;
					break;
				}
			}
		}
		
		printf("%d\n",func(1,0));
	}
}