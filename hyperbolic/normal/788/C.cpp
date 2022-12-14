#include <stdio.h>
#include <vector>
#include <queue>

std::queue<int> Q;
int check2[2010],ans[2010];
std::vector<int> V;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=b;i++)
	{
		int c;
		scanf("%d",&c);
		check2[c-a+1000] = 1;
	}
	for(int i=0;i<=2000;i++) if(check2[i]==1) V.push_back(i-1000);
	
	for(int i=0;i<V.size();i++) if(V[i]>=0) Q.push(V[i]);
	for(int i=0;i<V.size();i++) if(V[i]>=0) ans[V[i]] = 1;
	while(!Q.empty())
	{
		int k = Q.front();
		Q.pop();
		for(int i=0;i<V.size();i++)
		{
			int t = k+V[i];
			if(0<=t&&t<=2000)
			{
				if(ans[t]==0)
				{
					ans[t] = ans[k]+1;
					Q.push(t);
				}
			}
		}
	}
	if(ans[0]==0) printf("-1");
	else printf("%d",ans[0]);
	
}