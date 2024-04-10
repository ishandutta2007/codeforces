#include <stdio.h>
#include <vector>
#define MOD 1000000007

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

long long int count[100010];
std::vector<int> V[100010];
int main()
{
	int n;
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++) for(int j=i;j<=n;j+=i) V[j].push_back(i);
	
	long long int ans = 0;
	for(int c=1;c<=n-2;c++)
	{
		for(int j=0;j<V[n-c].size();j++) count[j] = (n-c-1)/V[n-c][j];
		for(int j=(int)V[n-c].size()-1;j>=0;j--) for(int k=j+1;k<V[n-c].size();k++) if(V[n-c][k]%V[n-c][j]==0) count[j] -= count[k];
		for(int j=0;j<V[n-c].size();j++)
		{
			long long int val = V[n-c][j] / gcd(V[n-c][j],n);
			ans += ((val*count[j])%MOD*c)%MOD, ans %= MOD;
		}
	}
	printf("%lld",ans);
}