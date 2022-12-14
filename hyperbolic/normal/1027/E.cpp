#include <stdio.h>
#include <vector>
#define MOD 998244353

int a;
std::vector<int> check[510];
void func(int k)
{
	if(check[k].size()>0) return;
	
	for(int i=0;i<=a;i++) check[k].push_back(0);
	
	for(int i=k+1;i<=a;i++)
	{
		func(i);
		std::vector<int> V = check[i];
		for(int j=1;j<=(i-k);j++) check[k][i-k] += V[j], check[k][i-k]%=MOD;
		for(int j=(i-k+1);j<=a;j++) check[k][j] += V[j], check[k][j]%=MOD;
	}
	check[k][a-k+1] += 1;
	check[k][a-k+1] %= MOD;
	
	return;
}

int limit;
long long int check2[510][510];
long long int func2(int s, int t)
{
	if(t>=limit) return 0;
	if(s>a) return 1;
	if(check2[s][t]!=-1) return check2[s][t];
	
	long long int s1 = func2(s+1,1);
	long long int s2 = func2(s+1,t+1);
	return check2[s][t] = (s1+s2)%MOD;
}

void clear(int k)
{
	for(int i=1;i<=a;i++) for(int j=0;j<=k;j++) check2[i][j] = -1;
}

std::vector<int> V;
int main()
{
	int b;
	scanf("%d%d",&a,&b);
	func(1);
	
	long long int ans = 0;
	for(int i=1;i<check[1].size();i++)
	{
		limit = ((b-1)/i)+1; // 1 ~ limit-1
		clear(limit<a?limit:a);
		ans += func2(1,0) * check[1][i];
		ans %= MOD;
	}
	printf("%lld",ans);
}