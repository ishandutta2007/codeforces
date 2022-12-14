#include <stdio.h>
#include <set>
#include <map>
#define MOD 1000000007
std::set<int> S1;
std::map<int,int> S2;
char x[110];
int main()
{
	std::set<int> ::iterator it1;
	std::map<int,int> ::iterator it2;
	int a;
	scanf("%d",&a);
	
	int count = 0;
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%s",x+1);
		scanf("%d",&b);
		if(x[2]=='D')
		{
			if(S2.size()==0)
			{
				if(S1.size()==0) S2[b] = 0;
				else
				{
					it1 = S1.end(),it1--;
					if((*it1)<b) S2[b] = 0;
					else S1.insert(b);
				}
			}
			else
			{
				it2 = S2.begin();
				if(S1.size()==0)
				{
					S2[b] = 0;
					it2 = S2.find(b);
					if(it2!=S2.begin())
					{
						it2--;
						if((it2->second)==2) S2[b] = 2;
					}
				}
				else
				{
					it1 = S1.end(),it1--;
					if((*it1)>b) S1.insert(b);
					else
					{
						S2[b] = 0;
						it2 = S2.find(b);
						if(it2!=S2.begin())
						{
							it2--;
							if((it2->second)==2) S2[b] = 2;
						}
					}
				}
			}
		}
		else
		{
			
			if(S1.find(b)!=S1.end())
			{
				it1 = S1.end(), it1--;
				if((*it1)==b)
				{
					S1.erase(it1);
					for(it2 = S2.begin();it2!=S2.end();it2++)
					{
						if(S2[it2->first]==2) break;
						S2[it2->first] = 2;
					}
				}
				else
				{
					printf("0");
					return 0;
				}
			}
			else
			{
				while(1)
				{
					it2 = S2.begin();
					if((it2->first)==b)
					{
						if((it2->second)==0) count++;
						S2.erase(it2);
						for(it2=S2.begin();it2!=S2.end();it2++)
						{
							if(S2[it2->first]==2) break;
							S2[it2->first] = 2;
						}
						break;
					}
					else if((it2->second)==2)
					{
						printf("0");
						return 0;
					}
					else
					{
						S1.insert(it2->first);
						S2.erase(it2); //
					}
				}
			}
		}
	}
	
	int count2 = 1;
	for(it2=S2.begin();it2!=S2.end();it2++) if((it2->second)==0) count2++;
	
	long long int ans = 1;
	for(int i=1;i<=count;i++) ans*=2,ans%=MOD;
	ans *= count2, ans%=MOD;
	printf("%lld",ans);
}