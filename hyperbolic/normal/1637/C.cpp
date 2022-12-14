#include <stdio.h>
#include <vector>

std::vector<int> V;
int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		if(a==3)
		{
			if(x[2]%2==1) printf("-1\n");
			else printf("%d\n",x[2]/2);
			continue;
		}
		
		int control = 0;
		for(int i=2;i<a;i++) if(x[i]>1) control = 1;
		if(control==0) printf("-1\n");
		else
		{
			long long int ans = 0;
			for(int i=2;i<a;i++) ans += (x[i]+1)/2;
			printf("%lld\n",ans);
		}
	}
}