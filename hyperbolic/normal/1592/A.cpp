#include <stdio.h>
#include <algorithm>

int x[1010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		
		int s = b/(x[a]+x[a-1]);
		int t = b%(x[a]+x[a-1]);
		if(t==0) printf("%d\n",2*s);
		else if(t<=x[a]) printf("%d\n",2*s+1);
		else printf("%d\n",2*s+2);
	}
}