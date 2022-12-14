#include <stdio.h>
#include <set>
#include <vector>

std::multiset<int> S;
std::set<int> T;
int x[100010],y[100010],z[100010];
std::vector<int> V[100010],ans;
int save[100010];

int main()
{
	int Case;
	scanf("%d",&Case);
	while(Case--)
	{
		ans.clear();
		S.clear();
		T.clear();
		
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) V[i].clear();
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		for(int i=1;i<=a;i++) save[y[i]] = i;
		
		for(int i=1;i<=a;i++) T.insert(y[i]);
		for(int i=1;i<=a;i++)
		{
			if(x[i]!=y[i])
			{
				S.insert(y[i]);
				V[y[i]].push_back(i);
			}
		}
		for(int i=1;i<=b;i++) scanf("%d",&z[i]);
		
		int index = 0;
		for(int i=1;i<=a;i++) if(y[i]==z[b]) index = i;
		
		for(int i=1;i<=b;i++)
		{
			int c = z[i];
			std::multiset<int> ::iterator it = S.find(c);
			if(it==S.end())
			{
				if(S.size()==0)
				{
					if(T.find(c)==T.end())
					{
						if(index==0)
						{
							printf("NO\n");
							goto v;
						}
						else ans.push_back(index);
					}
					else ans.push_back(save[c]);
				}
				else ans.push_back(V[*S.begin()].back());
			}
			else
			{
				ans.push_back(V[*it].back());
				V[*it].pop_back();
				S.erase(it);
			}
		}
		
		if(S.size()==0)
		{
			printf("YES\n");
			for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
			printf("\n");
		}
		else printf("NO\n");
		v:;
	}
}