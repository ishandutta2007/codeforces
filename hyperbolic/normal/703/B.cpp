#include <stdio.h>
int x[100010],y[100010],check[100010];
int main()
{
	int a,b,c;
	long long int sum=0,ans=0,ans2=0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++)
	{
		scanf("%d",&c);
		check[c] = 1;
		sum+=x[c];
	}
	
	int t = 1;
	for(int i=1;i<=a;i++) if(check[i]==0) ans+=sum*x[i];
	ans2+=sum*sum;
	for(int i=1;i<=a;i++) if(check[i]==1) ans2-=x[i]*x[i];
	for(int i=1;i<=a;i++) if(check[i]==0&&check[i+1]==0) ans+=x[i]*x[i+1];
	if(check[1]==0&&check[a]==0) ans+=x[1]*x[a];
	printf("%I64d",ans+ans2/2);
}