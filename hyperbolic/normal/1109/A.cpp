#include <stdio.h>

int x[300010],y[300010];
int save[3000010][3];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) y[i] = y[i-1]^x[i];
	for(int i=1;i<=a;i++) save[y[i]][i%2]++;
	
	long long int ans = 0;
	for(int i=0;i<=3000000;i++)
	{
		long long int s1 = save[i][0];
		long long int s2 = save[i][1];
		
		ans += s1*(s1-1)/2;
		ans += s2*(s2-1)/2;
	}
	ans += save[0][0];
	printf("%lld",ans);
}