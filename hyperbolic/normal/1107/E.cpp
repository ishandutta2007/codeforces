#include <stdio.h>
#include <vector>

std::vector<int> V;
int x[110];
char z[110];
long long int y[110];
long long int check[110][110][110];

long long int func(int L, int R, int k)
{
	if(L>R) return y[k];
	if(check[L][R][k]) return check[L][R][k];
	
	long long int ans = y[k+V[L]] + func(L+1,R,0);
	for(int i=L+1;i<=R;i+=2)
	{
		long long int t = func(L+1,i,0) + func(i+1,R,k+V[L]);
		ans = ans>t?ans:t;
	}
	return check[L][R][k] = ans;
}

int main()
{
	int a;
	scanf("%d",&a);
	scanf("%s",z+1);
	
	int C = 1;
	for(int i=2;i<=a+1;i++)
	{
		if(z[i]!=z[i-1])
		{
			V.push_back(C);
			C = 1;
		}
		else C++;
	}
	
	
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++)
	{
		y[i] = x[i];
		for(int j=1;j<i;j++) y[i] = y[i]>x[j]+y[i-j]?y[i]:x[j]+y[i-j];
	}
	
	printf("%lld",func(0,V.size()-1,0));
}