#include <stdio.h>
#include <vector>
#include <queue>

struct str{
	int first;
	int second;
};
bool operator<(str a, str b)
{
	return a.second>b.second;
}
std::priority_queue<str> Q;

std::vector<int> V[110];
char x[200010];
int sum[200010];
int DP[1000010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int c = (1<<b);
	
	scanf("%s",x+1);
	int min = 1, max = a;
	int ans = 0;
	while(min<=max)
	{
		int h = (min+max)/2;
		
		for(int j=1;j<=b;j++) V[j].clear();
		for(int i=0;i<c;i++) DP[i] = -1;
		
		for(int j=1;j<=b;j++)
		{
			for(int i=1;i<=a;i++)
			{
				if('a'<=x[i]&&x[i]<='z'&&x[i]=='a'+j-1) sum[i] = sum[i-1]+1;
				else if(x[i]=='?') sum[i] = sum[i-1]+1;
				else sum[i] = sum[i-1];
			}
			for(int i=1;i+h-1<=a;i++) if(sum[i+h-1]-sum[i-1]==h) V[j].push_back(i);
		}
		
		for(int j=1;j<=b;j++) if(!V[j].empty()) Q.push({1<<(j-1),V[j][0]});
		
		while(!Q.empty())
		{
			str A = Q.top();
			Q.pop();
			if(DP[A.first]!=-1) continue;
			DP[A.first] = A.second;
			for(int j=1;j<=b;j++)
			{
				if((A.first&(1<<(j-1)))==0)
				{
					int L = 0, R = V[j].size()-1;
					int p = -1;
					while(L<=R)
					{
						int h2 = (L+R)/2;
						if(V[j][h2]>=A.second+h)
						{
							p = h2;
							R = h2-1;
						}
						else L = h2+1;
					}
					if(p!=-1) Q.push({A.first + (1<<(j-1)),V[j][p]});
				}
			}
		}
		
		if(DP[c-1]!=-1)
		{
			ans = h;
			min = h+1;
		}
		else max = h-1;
	}
	printf("%d",ans);
}