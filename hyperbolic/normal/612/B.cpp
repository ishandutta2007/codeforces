#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}

int x[200010],pos[200010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) pos[x[i]] = i;
	
	long long int ans = 0;
	for(int i=1;i<a;i++) ans += abs(pos[i+1]-pos[i]);
	printf("%lld",ans);
}