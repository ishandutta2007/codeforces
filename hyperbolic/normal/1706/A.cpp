#include <stdio.h>

int x[110];
char ans[110];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int j=1;j<=b;j++) ans[j] = 'B';
		
		for(int i=1;i<=a;i++)
		{
			int val = x[i]<b+1-x[i]?x[i]:b+1-x[i];
			if(ans[val]=='B') ans[val] = 'A';
			else ans[b+1-val] = 'A';
		}
		for(int i=1;i<=b;i++) printf("%c",ans[i]);
		printf("\n");
	}
}