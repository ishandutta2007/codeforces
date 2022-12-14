#include <stdio.h>
#include <map>
#include <algorithm>

int x[200010],y[200010];
std::pair<int,int> P[300010];
std::map<int,int> M;
bool cmp1(std::pair<int,int> A, std::pair<int,int> B)
{
	if(A.first==B.first) return A.second<B.second;
	return A.first<B.first;
}
bool cmp2(std::pair<int,int> A, std::pair<int,int> B)
{
	if(A.second==B.second) return A.first<B.first;
	return A.second<B.second;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int j=1;j<=b;j++) scanf("%d",&y[j]);
		for(int i=1;i<=c;i++)
		{
			int d,e;
			scanf("%d%d",&d,&e);
			P[i] = std::make_pair(d,e);
		}
		
		long long int ans = 0;
		
		int L, R;
		std::sort(P+1,P+c+1,cmp1);
		L = R = 1;
		for(int i=1;i<a;i++)
		{
			while(L<=c&&P[L].first<=x[i]) L++;
			while(R<=c&&P[R].first<x[i+1]) R++;
			if(L==R) continue;
			int t = (R-L);
			ans += (long long int)t*(t-1)/2;
			
			M.clear();
			for(int j=L;j<R;j++) M[P[j].second]++;
			for(std::map<int,int> ::iterator it = M.begin();it!=M.end();it++)
			{
				int t = (it->second);
				ans -= (long long int)t*(t-1)/2;
			}
		}
		
		std::sort(P+1,P+c+1,cmp2);
		L = R = 1;
		for(int i=1;i<b;i++)
		{
			while(L<=c&&P[L].second<=y[i]) L++;
			while(R<=c&&P[R].second<y[i+1]) R++;
			if(L==R) continue;
			int t = (R-L);
			ans += (long long int)t*(t-1)/2;
			
			M.clear();
			for(int j=L;j<R;j++) M[P[j].first]++;
			for(std::map<int,int> ::iterator it = M.begin();it!=M.end();it++)
			{
				int t = (it->second);
				ans -= (long long int)t*(t-1)/2;
			}
		}
		printf("%lld\n",ans);
	}
}