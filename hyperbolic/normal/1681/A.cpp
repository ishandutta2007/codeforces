#include <stdio.h>
#include <algorithm>

int x[110],y[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int b;
		scanf("%d",&b);
		for(int i=1;i<=b;i++) scanf("%d",&y[i]);
		std::sort(x+1,x+a+1);
		std::sort(y+1,y+b+1);
		
		if(x[a]>y[b]) printf("Alice\nAlice\n");
		else if(x[a]<y[b]) printf("Bob\nBob\n");
		else printf("Alice\nBob\n");
	}
}