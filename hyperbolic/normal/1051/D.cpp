#include <stdio.h>
#define MOD 998244353

long long int check[1010][2010][3][3];
int a,b;
int func(int s, int k, int t1, int t2)
{
	if(k>b) return 0;
	if(s>a)
	{
		if(k==b) return 1;
		else return 0;
	}
	if(check[s][k][t1][t2]!=-1) return check[s][k][t1][t2];
	
	int C = 0;
	if(t1==1&&t2==1) C++;
	long long int s1 = func(s+1,k+C,0,0);
	
	C = 0;
	if(t1==0) C++;
	if(t2==1) C++;
	long long int s2 = func(s+1,k+C,1,0);
	
	C = 0;
	if(t1==1) C++;
	if(t2==0) C++;
	long long int s3 = func(s+1,k+C,0,1);
	
	C = 0;
	if(t1==0&&t2==0) C++;
	long long int s4 = func(s+1,k+C,1,1);
	return check[s][k][t1][t2] = (s1+s2+s3+s4)%MOD;
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) for(int k1=0;k1<=1;k1++) for(int k2=0;k2<=1;k2++) check[i][j][k1][k2] = -1;
	
	long long int s1 = func(2,1,0,0);
	long long int s2 = func(2,2,0,1);
	long long int s3 = func(2,2,1,0);
	long long int s4 = func(2,1,1,1);
	printf("%lld",(s1+s2+s3+s4)%MOD);
}