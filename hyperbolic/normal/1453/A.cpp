#include <stdio.h>
#include <map>

std::map<int,int> M;
int x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		M.clear();
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=b;i++) scanf("%d",&y[i]);
		for(int i=1;i<=a;i++) M[x[i]] = 1;
		
		int ans = 0;
		for(int i=1;i<=b;i++) ans += M[y[i]];
		printf("%d\n",ans);
	}
}