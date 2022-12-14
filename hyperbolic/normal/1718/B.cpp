#include <stdio.h>
#include <set>
#include <vector>

std::vector<int> fibo;
std::vector<long long int> fiboSum;

std::set< std::pair<int,int> > S;
int main()
{
	fibo.push_back(1);
	fibo.push_back(1);
	while(1)
	{
		int s1 = fibo[fibo.size()-1] + fibo[fibo.size()-2];
		fibo.push_back(s1);
		if(s1>(int)1e9) break;
	}
	fiboSum.push_back(fibo[0]);
	for(int i=1;i<fibo.size();i++) fiboSum.push_back(fiboSum.back() + fibo[i]);
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		std::set< std::pair<int,int> > ::iterator it;
		int a;
		scanf("%d",&a);
		
		long long int sum = 0;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			S.insert(std::make_pair(b,i));
			sum += b;
		}
		
		if(a==1)
		{
			if((*S.begin()).first==1) printf("YES\n");
			else printf("NO\n");
			continue;
		}
		
		int p = -1;
		for(int i=0;i<fiboSum.size();i++) if(fiboSum[i]==sum) p = i;
		if(p==-1)
		{
			printf("NO\n");
			continue;
		}
		
		int last = -1;
		for(int i=p;i>=0;i--)
		{
			std::set< std::pair<int,int> > ::iterator it1, it2;
			it1 = S.end(); it1--;
			int val1 = (it1->first), ind1 = (it1->second);
			S.erase(it1);
			it2 = S.end(); it2--;
			int val2 = (it2->first), ind2 = (it2->second);
			S.erase(it2);
			
			if(val1<fibo[i])
			{
				printf("NO\n");
				goto u;
			}
			
			if(val2<fibo[i])
			{
				if(ind1==last)
				{
					printf("NO\n");
					goto u;
				}
				else
				{
					val1 -= fibo[i];
					last = ind1;
					S.insert(std::make_pair(val1,ind1));
					S.insert(std::make_pair(val2,ind2));
				}
			}
			else
			{
				if(val1>val2)
				{
					if(ind1==last)
					{
						printf("NO\n");
						goto u;
					}
					else
					{
						val1 -= fibo[i];
						last = ind1;
						S.insert(std::make_pair(val1,ind1));
						S.insert(std::make_pair(val2,ind2));
					}
				}
				else if(val1<val2)
				{
					if(ind2==last)
					{
						printf("NO\n");
						goto u;
					}
					else
					{
						val2 -= fibo[i];
						last = ind2;
						S.insert(std::make_pair(val1,ind1));
						S.insert(std::make_pair(val2,ind2));
					}
				}
				else
				{
					if(val1>fibo[i])
					{
						printf("NO\n");
						goto u;
					}
					if(last==ind1)
					{
						val2 -= fibo[i];
						last = ind2;
						S.insert(std::make_pair(val1,ind1));
						S.insert(std::make_pair(val2,ind2));
					}
					else
					{
						val1 -= fibo[i];
						last = ind1;
						S.insert(std::make_pair(val1,ind1));
						S.insert(std::make_pair(val2,ind2));
					}
				}
			}
		}
		
		it = S.end();
		it--;
		if(it->first==0) printf("YES\n");
		else printf("NO\n");
		u:;
	}
}