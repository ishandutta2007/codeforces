#include <stdio.h>

long long int MAX = 1;
long long int first[1000010],second[1000010];
long long int DP[1000010][3];
int main()
{
	for(int i=1;i<=17;i++) MAX*=10;
	
	int a;
	long long int r1,r2,r3,d;
	scanf("%d",&a);
	scanf("%lld%lld%lld%lld",&r1,&r2,&r3,&d);
	for(int i=1;i<=a;i++)
	{
		long long int b;
		scanf("%lld",&b);
		first[i] = r1*b+r3<r3*b+r3?r1*b+r3:r3*b+r3;
		
		long long int c = r1<r2?r3<r1?r3:r1:r3<r2?r3:r2;
		second[i] = r1*(b+1)<r2?r1*(b+1):r2;
		second[i] = second[i]<r3*b+r1?second[i]:r3*b+r1;
		second[i] += c;
	}
	
	DP[0][2] = MAX;
	for(int i=1;i<=a;i++)
	{
		DP[i][1] = DP[i-1][1] + first[i] < DP[i-1][2] + second[i]? DP[i-1][1] + first[i] : DP[i-1][2] + second[i];
		DP[i][1] = DP[i][1] < DP[i-1][2] + first[i]? DP[i][1] : DP[i-1][2] + first[i];
		DP[i][2] = DP[i-1][1] + second[i] + 2*d;
	}
	long long int s1 = DP[a][1];
	long long int s2 = DP[a][2];
	long long int s3 = DP[a-1][2] + first[a] - d;
	long long int s = s1<s2?s1<s3?s1:s3:s2<s3?s2:s3;
	printf("%lld",s+(a-1)*d);
}