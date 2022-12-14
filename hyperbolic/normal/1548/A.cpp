#include <stdio.h>
#include <set>

std::set<int> S[200010];
int check[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		S[c].insert(d);
		S[d].insert(c);
	}
	
	for(int i=1;i<=a;i++)
	{
		std::set<int> ::iterator it = S[i].end();
		if(it==S[i].begin()) check[i] = 1;
		else
		{
			it--;
			if((*it)<i) check[i] = 1;
		}
	}
	
	int ans = 0;
	for(int i=1;i<=a;i++) ans += check[i];
	
	int c;
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		int d;
		scanf("%d",&d);
		if(d==1)
		{
			int e,f;
			scanf("%d%d",&e,&f);
			ans -= check[e], ans -= check[f];
			
			S[e].insert(f);
			S[f].insert(e);
			std::set<int> ::iterator it = S[e].end();
			it--;
			if((*it)<e) check[e] = 1;
			else check[e] = 0;
			it = S[f].end();
			it--;
			if((*it)<f) check[f] = 1;
			else check[f] = 0;
			ans += check[e], ans += check[f];
		}
		if(d==2)
		{
			int e,f;
			scanf("%d%d",&e,&f);
			ans -= check[e], ans -= check[f];
			
			S[e].erase(f);
			S[f].erase(e);
			std::set<int> ::iterator it = S[e].end();
			if(it==S[e].begin()) check[e] = 1;
			else
			{
				it--;
				if((*it)<e) check[e] = 1;
				else check[e] = 0;
			}
			it = S[f].end();
			if(it==S[f].begin()) check[f] = 1;
			else
			{
				it--;
				if((*it)<f) check[f] = 1;
				else check[f] = 0;
			}
			ans += check[e], ans += check[f];
		}
		if(d==3) printf("%d\n",ans);
	}
}