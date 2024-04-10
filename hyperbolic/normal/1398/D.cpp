#include <stdio.h>
#include <algorithm>

int x[210],y[210],z[210];
long long int check[210][210][210];
long long int func(int s, int t, int k)
{
	if(check[s][t][k]!=-1) return check[s][t][k];
	long long int s1 = 0,s2 = 0, s3 = 0;
	if(s>=1&&t>=1) s1 = func(s-1,t-1,k) + x[s]*y[t];
	if(t>=1&&k>=1) s2 = func(s,t-1,k-1) + y[t]*z[k];
	if(s>=1&&k>=1) s3 = func(s-1,t,k-1) + x[s]*z[k];
	return check[s][t][k] = s1>s2?s1>s3?s1:s3:s2>s3?s2:s3;
}
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) for(int k=0;k<=c;k++) check[i][j][k] = -1;
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=b;i++) scanf("%d",&y[i]);
	for(int i=1;i<=c;i++) scanf("%d",&z[i]);
	std::sort(x+1,x+a+1);
	std::sort(y+1,y+b+1);
	std::sort(z+1,z+c+1);
	
	printf("%lld",func(a,b,c));
}