#include <stdio.h>
#include <vector>

std::vector<int> V[200010];
std::pair<int,int> check[200010][3];

std::pair<int,int> func(int k, int prev, int type)
{
	if(check[k][type].first!=-1) return check[k][type];
	if(type==1)
	{
		int ans = 1;
		int ans2 = V[k].size();
		for(int i=0;i<V[k].size();i++)
		{
			if(V[k][i]==prev) continue;
			std::pair<int,int> P = func(V[k][i],k,0);
			ans += P.first;
			ans2 += P.second;
		}
		return check[k][type] = std::make_pair(ans,ans2);
	}
	else
	{
		int ans = 0;
		int ans2 = 1;
		for(int i=0;i<V[k].size();i++)
		{
			if(V[k][i]==prev) continue;
			std::pair<int,int> s1 = func(V[k][i],k,0);
			std::pair<int,int> s2 = func(V[k][i],k,1);
			
			if(s1.first>s2.first) ans += s1.first, ans2 += s1.second;
			else if(s1.first<s2.first) ans += s2.first, ans2 += s2.second;
			else
			{
				ans += s1.first;
				ans2 += (s1.second<s2.second?s1.second:s2.second);
			}
		}
		return check[k][type] = std::make_pair(ans,ans2);
	}
}

std::vector<int> ans;
void func2(int k, int prev, int type)
{
	if(type==1)
	{
		ans.push_back(k);
		for(int i=0;i<V[k].size();i++)
		{
			if(V[k][i]==prev) continue;
			func2(V[k][i],k,0);
		}
	}
	else
	{
		for(int i=0;i<V[k].size();i++)
		{
			if(V[k][i]==prev) continue;
			std::pair<int,int> s1 = func(V[k][i],k,0);
			std::pair<int,int> s2 = func(V[k][i],k,1);
			
			if(s1.first>s2.first) func2(V[k][i],k,0);
			else if(s1.first<s2.first) func2(V[k][i],k,1);
			else
			{
				if(s1.second<s2.second) func2(V[k][i],k,0);
				else func2(V[k][i],k,1);
			}
		}
	}
}

int check2[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		V[b].push_back(c);
		V[c].push_back(b);
	}
	if(a==2)
	{
		printf("2 2\n");
		printf("1 1");
		return 0;
	}
	
	for(int i=1;i<=a;i++) for(int j=0;j<=1;j++) check[i][j] = std::make_pair(-1,0);
	
	std::pair<int,int> s1 = func(1,0,0);
	std::pair<int,int> s2 = func(1,0,1);
	if(s1.first>s2.first) func2(1,0,0);
	else if(s1.first<s2.first) func2(1,0,1);
	else
	{
		if(s1.second<s2.second) func2(1,0,0);
		else func2(1,0,1);
	}
	
	for(int i=0;i<ans.size();i++) check2[ans[i]] = 1;
	
	int S = 0;
	for(int i=1;i<=a;i++)
	{
		if(check2[i]==1) S += V[i].size();
		else S++;
	}
	
	printf("%d %d\n",ans.size(),S);
	
	for(int i=1;i<=a;i++) printf("%d ",check2[i]==1?V[i].size():1);
}