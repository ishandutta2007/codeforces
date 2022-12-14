#include <stdio.h>

char x[1000010];
int main()
{
	int a;
	scanf("%d%s",&a,x+1);
	int p = 0;
	int count1 = 0, count2 = 0;
	int ans = 0;
	for(int i=1;i<=a;i++)
	{
		if(x[i]=='(') count1++;
		else if(x[i]==')') count2++;
		if(count1==count2)
		{
			if(x[p+1]==')') ans += 2*count1;
			p = i;
			count1 = count2 = 0;
		}
	}
	if(p==a) printf("%d",ans);
	else printf("-1");
}