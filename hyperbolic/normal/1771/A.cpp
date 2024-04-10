#include <stdio.h>

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
		int min = x[1], max = x[1];
		for(int i=1;i<=a;i++) min = min<x[i]?min:x[i];
		for(int i=1;i<=a;i++) max = max>x[i]?max:x[i];
		int c1 = 0, c2 = 0;
		for(int i=1;i<=a;i++) if(x[i]==min) c1++;
		for(int i=1;i<=a;i++) if(x[i]==max) c2++;
		
		if(min==max) printf("%lld\n",(long long int)a*(a-1));
		else printf("%lld\n",(long long int)2*c1*c2);
	}
}