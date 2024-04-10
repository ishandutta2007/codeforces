#include <stdio.h>
#include <string.h>

char x[300010];
int y[300010];
int main()
{
	scanf("%s",x+1);
	int a = strlen(x+1);
	for(int i=1;i<=a;i++) y[i] = x[i]-'0';
	
	long long int ans = 0;
	for(int i=2;i<=a;i++) if((10*y[i-1]+y[i])%4==0) ans += (i-1);
	for(int i=1;i<=a;i++) if(y[i]%4==0) ans++;
	printf("%lld",ans);
}