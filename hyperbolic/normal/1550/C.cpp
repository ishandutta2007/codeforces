#include <stdio.h>

int abs(int k)
{
	return k>0?k:-k;
}

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		int ans = 2*a-1;
		for(int i=1;i+2<=a;i++) if(abs(x[i]-x[i+1])+abs(x[i+1]-x[i+2])!=abs(x[i]-x[i+2])) ans++;
		for(int i=1;i+3<=a;i++)
		{
			int s1 = abs(x[i]-x[i+1])+abs(x[i+1]-x[i+2]) - abs(x[i]-x[i+2]);
			int s2 = abs(x[i]-x[i+1])+abs(x[i+1]-x[i+3]) - abs(x[i]-x[i+3]);
			int s3 = abs(x[i]-x[i+2])+abs(x[i+2]-x[i+3]) - abs(x[i]-x[i+3]);
			int s4 = abs(x[i+1]-x[i+2])+abs(x[i+2]-x[i+3]) - abs(x[i+1]-x[i+3]);
			if(s1!=0&&s2!=0&&s3!=0&&s4!=0) ans++;
		}
		printf("%d\n",ans);
	}
}