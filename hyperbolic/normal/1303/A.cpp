#include <stdio.h>
#include <string.h>

char x[100010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		scanf("%s",x+1);
		int b = strlen(x+1);
		int p1 = 1,p2 = b, ans = 0;
		for(int j=1;j<=b;j++) if(x[j]=='1') goto u;
		printf("0\n");
		continue;
		
		u:;
		for(;p1<=b;p1++) if(x[p1]=='1') break;
		for(;p2>=1;p2--) if(x[p2]=='1') break;
		for(int j=p1;j<=p2;j++) if(x[j]=='0') goto v;
		printf("0\n");
		continue;
		
		v:;
		for(;p1<=b;p1++) if(x[p1]=='0') break;
		for(;p2>=1;p2--) if(x[p2]=='0') break;
		for(int j=p1;j<=p2;j++) if(x[j]=='0') ans++;
		printf("%d\n",ans);
		
	}
}