#include <stdio.h>

char x[1000010],y[1000010];
int x2[1000010],y2[1000010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s%s",x+1,y+1);
	if(y[1]=='0')
	{
		printf("0");
		return 0;
	}
	
	if(x[1]=='0' && y[1]=='1')
	{
		for(int i=1;i<=a;i++) printf("1");
		return 0;
	}
	else
	{
		for(int i=1;i<=a;i++) x2[i] = x[i]-'0';
		for(int i=1;i<=a;i++) y2[i] = y[i]-'0';
		for(int i=1;i<=a;i++) if(x2[i]!=y2[i]) goto u;
		for(int i=1;i<=a;i++) printf("%c",y[i]);
		return 0;
		u:;
		x2[a]++;
		for(int i=a;i>=1;i--) if(x2[i]==2) x2[i-1]++, x2[i] = 0;
		for(int i=1;i<=a;i++) if(x2[i]!=y2[i]) goto v;
		for(int i=1;i<=a;i++) printf("%c",y[i]);
		return 0;
		v:;
		for(int i=1;i<a;i++) printf("%c",y[i]);
		printf("1");
		return 0;
	}
}