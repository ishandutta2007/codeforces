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
		int count = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]==')') count--;
			if(x[i]=='(') count++;
			if(count==-1) count = 0, ans++;
		}
		printf("%d\n",ans);
	}
}