#include <stdio.h>
#include <vector>

std::vector<int> V,ans;
char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		ans.clear();
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		int C = 0;
		for(int i=1;i<=2*a;i++) C += (x[i]-'0');
		if(C%2==1)
		{
			printf("-1\n");
			continue;
		}
		
		V.clear();
		for(int i=1;i<=2*a;i+=2) if(x[i]!=x[i+1]) V.push_back(i);
		
		for(int i=0;i<V.size();i++)
		{
			if(x[V[i]]=='0'+i%2) ans.push_back(V[i]);
			else ans.push_back(V[i]+1);
		}
		
		printf("%d\n",ans.size());
		for(int i=0;i<ans.size();i++) printf("%d ",ans[i]);
		printf("\n");
		for(int i=1;i<=2*a;i+=2) printf("%d ",i);
		printf("\n");
		
	}
}