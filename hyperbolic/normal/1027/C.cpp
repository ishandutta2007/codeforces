#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>

int x[1000010];
std::vector<int> V;

double ans;
int ans1, ans2;
std::map<int,int> M;
void clear()
{
	V.clear();
	M.clear();
	ans = 123456789;
	ans1 = ans2 = 0;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) M[x[i]]++;
		
		std::map<int,int> ::iterator it;
		for(it = M.begin();it!=M.end();it++)
		{
			if((it->second)>=4)
			{
				printf("%d %d %d %d\n",it->first,it->first,it->first,it->first);
				goto u;
			}
			if((it->second)>=2) V.push_back(it->first);
		}
		
		for(int i=0;i<V.size()-1;i++)
		{
			int s = V[i];
			int t = V[i+1];
			double value = (double)(s+t)*(s+t)/(s*t);
			if(ans>value)
			{
				ans = value;
				ans1 = s;
				ans2 = t;
			}
		}
		printf("%d %d %d %d\n",ans1,ans1,ans2,ans2);
		u:;
	}
}