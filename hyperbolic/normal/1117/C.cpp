#include <stdio.h>
long long int abs(long long int k)
{
	return k>0?k:-k;
}

char x[100010];
int saveX[100010],saveY[100010];
int main()
{
	long long int a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	
	int e;
	scanf("%d",&e);
	scanf("%s",x+1);
	for(int i=1;i<=e;i++)
	{
		if(x[i]=='U') saveY[i] = saveY[i-1]+1, saveX[i] = saveX[i-1];
		if(x[i]=='D') saveY[i] = saveY[i-1]-1, saveX[i] = saveX[i-1];
		if(x[i]=='R') saveX[i] = saveX[i-1]+1, saveY[i] = saveY[i-1];
		if(x[i]=='L') saveX[i] = saveX[i-1]-1, saveY[i] = saveY[i-1];
	}
	
	long long int MAX = 1;
	for(int i=1;i<=16;i++) MAX *= 10;
	
	long long int min = 0, max = MAX;
	long long int ans = MAX;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		long long int s1 = saveX[e]*(h/e) + saveX[h%e];
		long long int s2 = saveY[e]*(h/e) + saveY[h%e];
		long long int distX = abs(c-(a+s1));
		long long int distY = abs(d-(b+s2));
		if(distX+distY<=h)
		{
			ans = h;
			max = h-1;
		}
		else min = h+1;
	}
	if(ans==MAX) printf("-1");
	else printf("%lld",ans);
}