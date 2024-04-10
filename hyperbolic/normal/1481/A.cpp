#include <stdio.h>
#include <string.h>

char x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		int c = strlen(x+1);
		int s1 = 0, s2 = 0, s3 = 0, s4 = 0;
		for(int i=1;i<=c;i++)
		{
			if(x[i]=='U') s1++;
			if(x[i]=='D') s2++;
			if(x[i]=='R') s3++;
			if(x[i]=='L') s4++;
		}
		if(a>0&&s3<a) printf("NO\n");
		else if(a<0&&s4<(-a)) printf("NO\n");
		else if(b>0&&s1<b) printf("NO\n");
		else if(b<0&&s2<(-b)) printf("NO\n");
		else printf("YES\n");
	}
}