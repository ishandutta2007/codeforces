#include <stdio.h>
#include <set>
#include <vector>
#include <algorithm>

struct str{
	int first;
	int second;
	int type;
}x[100010];
bool cmp(str a, str b)
{
	if(a.first==b.first)
	{
		if(a.second==b.second) return a.type<b.type;
		return a.second<b.second;
	}
	return a.first<b.first;
}

std::multiset<int> S;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			int b,c,d;
			scanf("%d%d%d",&b,&c,&d);
			x[i] = {c,d,b+1};
		}
		std::sort(x+1,x+a+1,cmp);
		
		int control = 0;
		int ans = 0;
		int type = 0, limit = -1; //1:red 2 :blue
		for(int i=1;i<=a;i++)
		{
			while(!S.empty())
			{
				std::multiset<int> ::iterator it = S.begin();
				if((*it)<x[i].first)
				{
					ans++;
					S.erase(it);
				}
				else break;
			}
			if(S.size()==0) type = 0;
			
			if(limit<x[i].first) ans += control;
			
			if(x[i].first<=limit&&x[i].second<=limit) continue;
			
			control = 0;
			if(x[i].first<=limit)
			{
				if(type==0)
				{
					type = x[i].type;
					S.insert(x[i].second);
				}
				else
				{
					std::multiset<int> ::iterator it = S.end();
					it--;
					int val = (*it);
					S.clear();
					
					if(x[i].type==type) S.insert(x[i].second>val?x[i].second:val);
					else
					{
						limit = x[i].second<val?x[i].second:val;
						if(val<x[i].second)
						{
							type = x[i].type;
							S.insert(x[i].second);
						}
						else if(val>x[i].second) S.insert(val);
						else control = 1, type = 0;
					}
				}
			}
			else if(type==0)
			{
				type = x[i].type;
				S.insert(x[i].second);
			}
			else if(x[i].type==type) S.insert(x[i].second);
			else
			{
				std::multiset<int> ::iterator it = S.end();
				it--;
				int val = (*it);
				S.clear();
				limit = val<x[i].second?val:x[i].second;
				
				if(val<x[i].second)
				{
					type = x[i].type;
					S.insert(x[i].second);
				}
				else if(val>x[i].second) S.insert(val);
				else control = 1, type = 0;
			}
		}
		
		printf("%d\n",ans+S.size()+control);
	}
}