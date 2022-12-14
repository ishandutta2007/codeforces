#include <stdio.h>

int x[110],ans[110];
void func(int L, int R, int h)
{
	if(L>R) return;
	
	int max = x[L];
	for(int i=L;i<=R;i++) max = max>x[i]?max:x[i];
	int s = L;
	for(int i=L;i<=R;i++) if(max==x[i]) s = i;
	ans[s] = h;
	func(L,s-1,h+1);
	func(s+1,R,h+1);
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		func(1,a,0);
		for(int i=1;i<=a;i++) printf("%d ",ans[i]);
		printf("\n");
	}
}