#include <stdio.h>
#include <map>

std::map<int,int> M;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		
		M.clear();
		int max = 0;
		for(int i=1;i<=a;i++)
		{
			int b;
			scanf("%d",&b);
			M[b]++;
			max = max>M[b]?max:M[b];
		}
		
		int ans = 0;
		while(max<a)
		{
			ans++;
			int t = (a-max)<max?(a-max):max;
			max += t, ans += t;
		}
		printf("%d\n",ans);
	}
}