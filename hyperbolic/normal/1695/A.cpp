#include <stdio.h>

int x[110][110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) scanf("%d",&x[i][j]);
		
		int ans1 = 1, ans2 = 1;
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) if(x[ans1][ans2] < x[i][j]) ans1 = i, ans2 = j;
		
		int val1 = ans1>a-ans1+1?ans1:a-ans1+1;
		int val2 = ans2>b-ans2+1?ans2:b-ans2+1;
		printf("%d\n",val1*val2);
	}
}