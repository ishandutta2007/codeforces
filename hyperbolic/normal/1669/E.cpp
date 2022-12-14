#include <stdio.h>

char x[3];
int check1[110],check2[110],check3[10010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		for(int i=0;i<=100;i++) check1[i] = check2[i] = 0;
		for(int i=0;i<=10000;i++) check3[i] = 0;
		int a;
		scanf("%d",&a);
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			scanf("%s",x+1);
			int s = x[1]-'a', t = x[2]-'a';
			ans += check1[s];
			ans += check2[t];
			ans -= 2*check3[100*s+t];
			check1[s]++;
			check2[t]++;
			check3[100*s+t]++;
		}
		printf("%lld\n",ans);
	}
}