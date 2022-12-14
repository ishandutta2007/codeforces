#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
int a;
std::vector<char> V[200010];
std::vector<int> temp;
int func(char c)
{
	temp.clear();
	for(int i=1;i<=a;i++)
	{
		int count = 0;
		for(int j=0;j<V[i].size();j++)
		{
			if(V[i][j]==c) count++;
			else count--;
		}
		temp.push_back(count);
	}
	std::sort(temp.begin(),temp.end());
	
	int sum = 0;
	int ans = 0;
	for(int i=temp.size()-1;i>=0;i--)
	{
		sum += temp[i];
		if(sum>0) ans++;
		else return ans;
	}
	return ans;
}

char x[400010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&a);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++)
		{
			scanf("%s",x+1);
			int b = strlen(x+1);
			for(int j=1;j<=b;j++) V[i].push_back(x[j]);
		}
		
		int ans = 0;
		for(int i=0;i<5;i++)
		{
			int t = func('a'+i);
			ans = ans>t?ans:t;
		}
		printf("%d\n",ans);
	}
}