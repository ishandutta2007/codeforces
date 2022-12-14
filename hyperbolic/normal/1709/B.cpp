#include <stdio.h>

long long int next[100010],prev[100010];
int x[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<a;i++) next[i] = x[i]-x[i+1]>0?x[i]-x[i+1]:0;
	for(int i=2;i<=a;i++) prev[i] = x[i]-x[i-1]>0?x[i]-x[i-1]:0;
	for(int i=1;i<=a;i++) next[i] += next[i-1];
	for(int i=1;i<=a;i++) prev[i] += prev[i-1];
	
	while(b--)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		if(c<d) printf("%lld\n",next[d-1]-next[c-1]);
		else printf("%lld\n",prev[c]-prev[d]);
	}
}