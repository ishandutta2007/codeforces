#include <stdio.h>
#include <algorithm>
#include <map>
#include <queue>

std::map< std::pair<int,int> , int> M, inQueue;
std::pair<int,int> ans[200010];
std::queue< std::pair<int,int> > Q;

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b,c;
		scanf("%d%d",&b,&c);
		M[std::make_pair(b,c)] = i;
	}
	
	std::map< std::pair<int,int> , int > ::iterator it;
	for(it = M.begin();it!=M.end();it++)
	{
		std::pair<int,int> P = (it->first);
		if(M.find(std::make_pair(P.first+1,P.second))==M.end())
		{
			inQueue[P] = 1;
			ans[it->second] = std::make_pair(P.first+1,P.second);
			Q.push(P);
		}
		else if(M.find(std::make_pair(P.first-1,P.second))==M.end())
		{
			inQueue[P] = 1;
			ans[it->second] = std::make_pair(P.first-1,P.second);
			Q.push(P);
		}
		else if(M.find(std::make_pair(P.first,P.second+1))==M.end())
		{
			inQueue[P] = 1;
			ans[it->second] = std::make_pair(P.first,P.second+1);
			Q.push(P);
		}
		else if(M.find(std::make_pair(P.first,P.second-1))==M.end())
		{
			inQueue[P] = 1;
			ans[it->second] = std::make_pair(P.first,P.second-1);
			Q.push(P);
		}
	}
	
	while(!Q.empty())
	{
		std::pair<int,int> P = Q.front();
		Q.pop();
		
		if(M.find(std::make_pair(P.first+1,P.second))!=M.end() && inQueue.find(std::make_pair(P.first+1,P.second))==inQueue.end())
		{
			inQueue[std::make_pair(P.first+1,P.second)] = 1;
			ans[M[std::make_pair(P.first+1,P.second)]] = ans[M[P]];
			Q.push(std::make_pair(P.first+1,P.second));
		}
		if(M.find(std::make_pair(P.first-1,P.second))!=M.end() && inQueue.find(std::make_pair(P.first-1,P.second))==inQueue.end())
		{
			inQueue[std::make_pair(P.first-1,P.second)] = 1;
			ans[M[std::make_pair(P.first-1,P.second)]] = ans[M[P]];
			Q.push(std::make_pair(P.first-1,P.second));
		}
		if(M.find(std::make_pair(P.first,P.second+1))!=M.end() && inQueue.find(std::make_pair(P.first,P.second+1))==inQueue.end())
		{
			inQueue[std::make_pair(P.first,P.second+1)] = 1;
			ans[M[std::make_pair(P.first,P.second+1)]] = ans[M[P]];
			Q.push(std::make_pair(P.first,P.second+1));
		}
		if(M.find(std::make_pair(P.first,P.second-1))!=M.end() && inQueue.find(std::make_pair(P.first,P.second-1))==inQueue.end())
		{
			inQueue[std::make_pair(P.first,P.second-1)] = 1;
			ans[M[std::make_pair(P.first,P.second-1)]] = ans[M[P]];
			Q.push(std::make_pair(P.first,P.second-1));
		}
	}
	
	for(int i=1;i<=a;i++) printf("%d %d\n",ans[i].first,ans[i].second);
}