#include <stdio.h>
#include <set>
#include <algorithm>

std::multiset<int> S1,S2,S3;
int x[100010];

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	std::sort(x+1,x+a+1);
	for(int i=1;i<=a;i++) S1.insert(x[i]);
	for(int i=1;i<a;i++) S2.insert(x[i+1]-x[i]);
	
	std::multiset<int> ::iterator it1,it2,it3;
	if(S2.size()==0) printf("0\n");
	else
	{
		it1 = S1.end();
		it1--;
		it2 = S1.begin();
		it3 = S2.end();
		it3--;
		printf("%lld\n",(long long int)(*it1)-(*it2)-(*it3));
	}
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(c==1)
		{
			if(S1.size()==0)
			{
				S1.insert(d);
				goto u;
			}
			
			it1 = S1.upper_bound(d);
			if(it1==S1.begin())
			{
				int k = (*it1);
				S1.insert(d);
				S2.insert(k-d);
			}
			else if(it1==S1.end())
			{
				it1--;
				int k = (*it1);
				S1.insert(d);
				S2.insert(d-k);
			}
			else
			{
				int t = (*it1);
				it1--;
				int s = (*it1);
				it2 = S2.find(t-s);
				S2.erase(it2);
				S1.insert(d);
				S2.insert(t-d);
				S2.insert(d-s);
			}
		}
		else
		{
			it1 = S1.find(d);
			if(S1.size()==1)
			{
				S1.erase(it1);
				goto u;
			}
			
			if(it1==S1.begin())
			{
				it3 = it1;
				it3++;
				std::multiset<int> ::iterator it4 = S2.find((*it3)-(*it1));
				S2.erase(it4);
				S1.erase(it1);
			}
			else
			{
				it2 = it1;
				it2--;
				it3 = it1;
				it3++;
				
				if(it3==S1.end())
				{
					std::multiset<int> ::iterator it4 = S2.find((*it1)-(*it2));
					S2.erase(it4);
					S1.erase(it1);
				}
				else
				{
					std::multiset<int> ::iterator it4 = S2.find((*it1)-(*it2));
					S2.erase(it4);
					it4 = S2.find((*it3)-(*it1));
					S2.erase(it4);
					S2.insert((*it3)-(*it2));
					S1.erase(it1);
				}
			}
		}
		u:;
		
		if(S2.size()==0) printf("0\n");
		else
		{
			it1 = S1.end();
			it1--;
			it2 = S1.begin();
			it3 = S2.end();
			it3--;
			printf("%lld\n",(long long int)(*it1)-(*it2)-(*it3));
		}
	}
}