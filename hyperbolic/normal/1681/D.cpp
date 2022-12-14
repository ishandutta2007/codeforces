#include <stdio.h>
#include <map>
#define MAX 12345678

int a;
std::map<long long int,int> M;
int func(long long int k)
{
	if(M.find(k)!=M.end()) return M[k];
	int C = 0;
	long long int k2 = k;
	int check[11] = {};
	while(k2)
	{
		C++;
		check[k2%10]++;
		k2/=10;
	}
	if(C==a) return 0;
	
	long long int ans = MAX;
	for(int i=2;i<=9;i++)
	{
		if(check[i])
		{
			long long int val = func(k*i)+1;
			ans = ans<val?ans:val;
		}
	}
	return M[k] = ans;
}

int main()
{
	scanf("%d",&a);
	long long int b;
	scanf("%lld",&b);
	long long int ans = func(b);
	if(ans>=MAX) printf("-1");
	else printf("%d",ans);
}