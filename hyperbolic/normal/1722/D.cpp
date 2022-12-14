#include <stdio.h>
#include <set>

long long int ans[200010];
std::multiset<int> S;
char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		S.clear();
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		ans[0] = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='L') ans[0] += (i-1);
			else ans[0] += (a-i);
		}
		for(int i=1;i<=a;i++)
		{
			int val1 = i-1, val2 = a-i;
			if(x[i]=='L'&&val1<val2) S.insert(val2-val1);
			if(x[i]=='R'&&val1>val2) S.insert(val1-val2);
		}
		
		for(int i=1;i<=a;i++)
		{
			if(S.size()==0) ans[i] = ans[i-1];
			else
			{
				std::multiset<int> ::iterator it = S.end();
				it--;
				ans[i] = ans[i-1] + (*it);
				S.erase(it);
			}
		}
		
		for(int i=1;i<=a;i++) printf("%lld ",ans[i]);
		printf("\n");
	}
}