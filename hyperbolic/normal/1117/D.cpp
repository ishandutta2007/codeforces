#include <stdio.h>
#define MOD 1000000007
int b;
struct Matrix{
	long long int x[110][110];
}A,B,C;

Matrix operator*(Matrix A, Matrix B)
{
	Matrix C;
	for(int i=1;i<=b;i++)
	{
		for(int j=1;j<=b;j++)
		{
			C.x[i][j] = 0;
			for(int k=1;k<=b;k++)
			{
				C.x[i][j] += A.x[i][k] * B.x[k][j];
				C.x[i][j] %= MOD;
			}
		}
	}
	return C;
}

void func(long long int k)
{
	for(int i=1;i<=b;i++) for(int j=1;j<=b;j++) B.x[i][j] = C.x[i][j] = 0;
	for(int i=1;i<=b;i++) B.x[i][i] = C.x[i][i] = 1;
	
	C = A;
	while(k)
	{
		if(k%2==1) B = B * C;
		k/=2;
		C = C * C;
	}
}

int main()
{
	long long int a;
	scanf("%lld%d",&a,&b);
	for(int i=1;i<=b;i++) for(int j=1;j<=b;j++) A.x[i][j] = 0;
	A.x[1][1] = 1, A.x[1][b] = 1;
	for(int i=2;i<=b;i++) A.x[i][i-1] = 1;
	
	if(a<b)
	{
		printf("1");
		return 0;
	}
	func(a-b);
	
	long long int s = 0;
	for(int i=1;i<=b;i++) s += B.x[1][i], s %= MOD;
	s += B.x[1][1], s %= MOD;
	printf("%lld",s);
}