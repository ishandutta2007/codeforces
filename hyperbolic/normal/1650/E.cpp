#include <stdio.h>
#include <set>

std::multiset<int> S;
int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		int p = 1;
		int d = b+1;
		for(int i=1;i<=a;i++)
		{
			if(x[i]-x[i-1]-1<d)
			{
				d = x[i]-x[i-1]-1;
				p = i;
			}
		}
		
		S.clear();
		for(int i=1;i<=a;i++) S.insert(x[i]-x[i-1]-1);
		
		std::multiset<int> ::iterator it;
		int ans = d;
		//case 1
		
		it = S.find(x[p]-x[p-1]-1);
		S.erase(it);
		if(p+1<=a)
		{
			it = S.find(x[p+1]-x[p]-1);
			S.erase(it);
			S.insert(x[p+1]-x[p-1]-1);
		}
		if(p==a)
		{
			it = S.end();
			it--;
			int s = (*it);
			int t = b-x[a-1]-1;
			int m = t>(s-1)/2?t:(s-1)/2;
			it = S.begin();
			s = (*it);
			m = m<s?m:s;
			ans = ans>m?ans:m;
		}
		else
		{
			it = S.end();
			it--;
			int s = (*it);
			int t = b-x[a]-1;
			int m = t>(s-1)/2?t:(s-1)/2;
			it = S.begin();
			s = (*it);
			m = m<s?m:s;
			ans = ans>m?ans:m;
		}
		//case 2
		
		S.clear();
		for(int i=1;i<=a;i++) S.insert(x[i]-x[i-1]-1);
		if(p>=2)
		{
			
			it = S.find(x[p]-x[p-1]-1);
			S.erase(it);
			it = S.find(x[p-1]-x[p-2]-1);
			S.erase(it);
			S.insert(x[p]-x[p-2]-1);
			
			it = S.end();
			it--;
			int s = (*it);
			int t = b-x[a]-1;
			int m = t>(s-1)/2?t:(s-1)/2;
			it = S.begin();
			s = (*it);
			m = m<s?m:s;
			ans = ans>m?ans:m;
		}
		
		printf("%d\n",ans);
		
	}
}