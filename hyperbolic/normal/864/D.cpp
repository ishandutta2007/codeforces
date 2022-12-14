#include <stdio.h>
#include <set>
std::set<int> S;
int x[200010],check[200010];
int y[200010],check2[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) check[x[i]]++;
	for(int i=1;i<=a;i++) if(check[i]==0) S.insert(i);
	printf("%d\n",S.size());
	for(int i=1;i<=a;i++)
	{
		if(check[x[i]]>1)
		{
			if(x[i]>*(S.begin()))
			{
				y[i] = *(S.begin());
				S.erase(S.begin());
				check[x[i]]--;
			}
			else if(check2[x[i]]==0)
			{
				check2[x[i]] = 1;
				y[i] = x[i];
			}
			else
			{
				y[i] = *(S.begin());
				S.erase(S.begin());
				check[x[i]]--;
			}
		}
		else y[i] = x[i];
	}
	for(int i=1;i<=a;i++) printf("%d ",y[i]);
}