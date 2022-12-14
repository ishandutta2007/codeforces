#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 1234567890
#define MOD 998244353
 
struct str{
	int index;
	int first;
	int second;
};
bool operator<(str a, str b)
{
	if(a.second==b.second) return a.first>b.first;
	return a.second>b.second;
}
std::priority_queue<str> Q;
 
std::vector<int> V[200010],V2[200010];
std::pair<int,int> check[200010][30];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		V[c].push_back(d);
		V2[d].push_back(c);
	}
	for(int i=1;i<=a;i++) for(int j=0;j<=21;j++) check[i][j] = std::make_pair(-1,-1);
	Q.push({1,0,0});
	while(!Q.empty())
	{
		str A = Q.top();
		Q.pop();
		int t = A.second;
		if(t>=20)
		{
			if(t%2==0) t = 20;
			else t = 21;
		}
		
		if(check[A.index][t]!=std::make_pair(-1,-1)) continue;
		check[A.index][t] = std::make_pair(A.first,A.second);
		
		if(A.second%2==0)
		{
			for(int i=0;i<V[A.index].size();i++)
			{
				int s = V[A.index][i];
				if(check[s][t]==std::make_pair(-1,-1)) Q.push({s,A.first+1,A.second});
			}
			for(int i=0;i<V2[A.index].size();i++)
			{
				int s = V2[A.index][i];
				int t2 = A.second+1;
				if(t2>=20)
				{
					if(t2%2==0) t2 = 20;
					else t2 = 21;
				}
				if(check[s][t2]==std::make_pair(-1,-1)) Q.push({s,A.first+1,A.second+1});
			}
		}
		else
		{
			for(int i=0;i<V2[A.index].size();i++)
			{
				int s = V2[A.index][i];
				if(check[s][t]==std::make_pair(-1,-1)) Q.push({s,A.first+1,A.second});
			}
			for(int i=0;i<V[A.index].size();i++)
			{
				int s = V[A.index][i];
				int t2 = A.second+1;
				if(t2>=20)
				{
					if(t2%2==0) t2 = 20;
					else t2 = 21;
				}
				if(check[s][t2]==std::make_pair(-1,-1)) Q.push({s,A.first+1,A.second+1});
			}
		}
	}
	
	long long int ans = MAX;
	for(int i=0;i<20;i++)
	{
		if(check[a][i]==std::make_pair(-1,-1)) continue;
		long long int val = check[a][i].first + (1<<check[a][i].second) - 1;
		//printf("%d %d %lld!!\n",check[a][i].first,check[a][i].second,val);
		ans = ans<val?ans:val;
	}
	
	if(ans==MAX)
	{
		if(check[a][20]==std::make_pair(-1,-1))
		{
			long long int val1 = check[a][21].first;
			long long int S1 = 1;
			for(int i=1;i<=check[a][21].second;i++) S1*=2, S1%=MOD;
			printf("%lld",(val1+S1-1+MOD)%MOD);
		}
		else if(check[a][21]==std::make_pair(-1,-1))
		{
			long long int val1 = check[a][20].first;
			long long int S1 = 1;
			for(int i=1;i<=check[a][20].second;i++) S1*=2, S1%=MOD;
			printf("%lld",(val1+S1-1+MOD)%MOD);
		}
		else
		{
			long long int val2 = check[a][21].first;
			long long int S2 = 1;
			for(int i=1;i<=check[a][21].second;i++) S2*=2, S2%=MOD;
			
			long long int val1 = check[a][20].first;
			long long int S1 = 1;
			for(int i=1;i<=check[a][20].second;i++) S1*=2, S1%=MOD;
			if(check[a][20].second<check[a][21].second) printf("%lld",(val1+S1-1+MOD)%MOD);
			else if(check[a][20].second>check[a][21].second) printf("%lld",(val2+S2-1+MOD)%MOD);
			else
			{
				if(check[a][20].first<check[a][21].first) printf("%lld",(val1+S1-1+MOD)%MOD);
				else printf("%lld",(val2+S2-1+MOD)%MOD);
			}
		}
	}
	else printf("%lld",ans%MOD);
}