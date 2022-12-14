#include <stdio.h>
#include <algorithm>
#include <set>

struct str{
	int first;
	int second;
	int index;
}x[500010];
bool cmp(str a, str b)
{
	if(a.first==b.first) return a.index<b.index;
	return a.first<b.first;
}

int ans[500010];
std::set< std::pair<int,int> > S;
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
			int b;
			scanf("%d",&b);
			int L,R;
			L = i/(b+1)+1;
			if(b==0) R = a;
			else R = i/b;
			x[i] = {L,R,i};
		}
		std::sort(x+1,x+a+1,cmp);
		int p = 1;
		for(int i=1;i<=a;i++)
		{
			while(p<=a && x[p].first<=i)
			{
				S.insert(std::make_pair(x[p].second,x[p].index));
				p++;
			}
			std::set< std::pair<int,int> > ::iterator it = S.begin();
			ans[it->second] = i;
			S.erase(it);
		}
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}