#include <stdio.h>

int x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	int min = x[1], max = x[1];
	for(int i=2;i<=a;i++) min = min<x[i]?min:x[i];
	for(int i=2;i<=a;i++) max = max>x[i]?max:x[i];
	
	int ans = 0;
	for(int i=1;i<=a;i++) if(min<x[i] && x[i]<max) ans++;
	printf("%d",ans);
}