#include <stdio.h>

char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		int ans = 0;
		for(int i=1;i<a;i++) if(x[i]!=x[i+1]) ans++;
		
		if(ans==0) printf("0\n");
		else
		{
			if(x[1]=='0') ans--;
			printf("%d\n",ans);
		}
	}
}