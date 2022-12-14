#include <stdio.h>
#include <vector>

std::vector<int> V;
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=2;i<=100000;i++)
	{
		while(a%i==0)
		{
			V.push_back(i);
			a/=i;
		}
	}
	if(V.size()<b) printf("-1");
	else
	{
		int ans = 1;
		for(int i=0;i<b-1;i++) printf("%d ",V[i]);
		for(int i=b-1;i<V.size();i++) ans *= V[i];
		printf("%d",ans);
	}
}