#include <stdio.h>

char x[300010];
int next[300010];
int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",x+1);
	int p1 = a+1, p2 = a+1;
	for(int i=a;i>=1;i--)
	{
		if(x[i]=='A') next[i] = p2, p1 = i;
		if(x[i]=='B') next[i] = p1, p2 = i;
	}
	long long int ans = (long long int)a*(a-1)/2;
	for(int i=1;i<=a;i++)
	{
		if(x[i]!=x[i-1])
		{
			int t = next[i]-i;
			if(i==1&&next[i]==a+1);
			else if(i==1) ans -=t;
			else if(next[i]==a+1) ans -= t;
			else ans -= (2*t);
		}
	}
	for(int i=1;i<a;i++) if(x[i]!=x[i+1]) ans++;
	printf("%lld",ans);
}