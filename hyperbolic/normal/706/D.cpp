#include <stdio.h>
#include <set>
#include <map>
std::set<int> S;
std::map<int,int> M;
std::multiset<int> ::iterator it;
int p[40];
int main()
{
	int a,c;
	char b;
	scanf("%d",&a);
	S.insert(0);
	p[0] = 1;
	for(int i=1;i<=30;i++) p[i] = p[i-1]*2;
	for(int i=1;i<=a;i++)
	{
		scanf("\n%c",&b);
		if(b=='+')
		{
			scanf("%d",&c);
			if(M[c]==0) S.insert(c);
			M[c]++;
		}
		else if(b=='-')
		{
			scanf("%d",&c);
			M[c]--;
			if(M[c]==0) S.erase(c);
		}
		else if(b=='?')
		{
			scanf("%d",&c);
			int ans = 0;
			int min = 0, max = p[30]-1;
			for(int j=29;j>=0;j--)
			{
				if(2*p[j]>c&&c>=p[j])
				{
					it = S.lower_bound(min);
					if(*it<min+p[j])
					{
						max-=p[j];
						ans+=p[j];
					}
					else min+=p[j];
					c-=p[j];
				}
				else
				{
					it = S.lower_bound(min+p[j]);
					if(it==S.end()) max-=p[j];
					else if(*it<=max)
					{
						min+=p[j];
						ans+=p[j];
					}
					else max-=p[j];
				}
			}
			printf("%d\n",ans);
		}
	}
}