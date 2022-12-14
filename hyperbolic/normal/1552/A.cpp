#include <stdio.h>
#include <algorithm>

char x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d%s",&a,x+1);
		for(int i=1;i<=a;i++) y[i] = x[i];
		std::sort(y+1,y+a+1);
		int ans = a;
		for(int i=1;i<=a;i++) if(x[i]==y[i]) ans--;
		printf("%d\n",ans);
	}
}