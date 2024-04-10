#include <stdio.h>

long long int MIN = -1;
int a;
long long int check[100010][4];
int x[100010],y[100010];
long long int func(int s, int t)
{
	if(s>a) return 0;
	if(check[s][t]!=-1) return check[s][t];
	
	long long int S1 = MIN,S2 = MIN,S3 = MIN;
	if(t!=1) S1 = func(s+1,1) + x[s];
	if(t!=2) S2 = func(s+1,2) + y[s];
	S3 = func(s+1,0);
	
	long long int max = S1;
	max = max>S2?max:S2;
	max = max>S3?max:S3;
	return check[s][t] = max;
}
int main()
{
	for(int i=1;i<=15;i++) MIN*=10;
	
	scanf("%d",&a);
	for(int i=1;i<=a;i++) for(int j=0;j<=2;j++) check[i][j] = -1;
	
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) scanf("%d",&y[i]);
	
	printf("%lld",func(1,0));
}