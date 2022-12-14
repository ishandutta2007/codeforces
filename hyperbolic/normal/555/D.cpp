#include <stdio.h>
#include <set>
#include <map>
#include <algorithm>
#include <vector>
int x[200010];
std::vector<int> index;
std::set<int> S;
std::map<int,int> hash;

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) hash[x[i]] = i;
	for(int i=1;i<=a;i++) S.insert(x[i]);
	
	std::set<int> ::iterator it;
	for(int i=1;i<=b;i++)
	{
		int c,d,c2,d2,c3,d3;
		scanf("%d%d",&c,&d);
		c = x[c];
		while(1)
		{
			it = S.upper_bound(c+d);
			if(it==S.begin()) c2 = c, d2 = d;
			else
			{
				it--;
				c2 = (*it);
				d2 = (c+d-c2);
			}
			
			it = S.lower_bound(c2-d2);
			if(it==S.end()) c3 = c2, d3 = d2;
			else
			{
				c3 = (*it);
				d3 = (c3+d2-c2);
			}
			if(c==c3&&d==d3)
			{
				printf("%d\n",hash[c]);
				break;
			}
			else if(c==c3)
			{
				int l = (d-d3);
				d3%=l;
			}
			c = c3, d = d3;
		}
	}
}