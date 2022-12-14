#include <stdio.h>
#include <algorithm>

int x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		for(int i=1;i<=b;i++) scanf("%d",&x[i]);
		for(int i=1;i<=c;i++) scanf("%d",&y[i]);
		std::sort(x+1,x+b+1);
		std::sort(y+1,y+c+1);
		if(x[b]>y[c]) printf("YES\n");
		else printf("NO\n");
	}
}