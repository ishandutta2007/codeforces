#include <stdio.h>
#include <map>
#define MOD 1000000007

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans %= MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}

long long int check2[1010][1010];
long long int comb(int a, int b)
{
	if(a==b) return 1;
	if(b==0) return 1;
	if(check2[a][b]) return check2[a][b];
	return check2[a][b] = (comb(a-1,b-1)+comb(a-1,b))%MOD;
}

int a;
int check[110];
std::map< std::pair<int,long long int> , long long int> M;
long long int func(int k, long long int val)
{
	if(k<0) return 1;
	long long int t = 1LL<<k;
	if((2*t-1)<=val/a)
	{
		long long int s = power(2,a-1);
		long long int t = power(s,k+1);
		return t;
	}
	
	if(M.find(std::make_pair(k,val))!=M.end()) return M[std::make_pair(k,val)];
	
	long long int ans = 0;
	for(int i=check[k];i<=a&&i*t<=val;i+=2)
	{
		long long int s = comb(a,i);
		s *= func(k-1,val-i*t), s %= MOD;
		ans += s, ans %= MOD;
	}
	return M[std::make_pair(k,val)] = ans;
}

int main()
{
	long long int b,c,d;
	scanf("%d%lld%lld%lld",&a,&b,&c,&d);
	
	for(int i=0;i<=60;i++)
	{
		check[i] = d%2;
		d/=2;
	}
	
	long long int s1 = func(60,c);
	long long int s2 = func(60,b-1);
	printf("%lld",(s1-s2+MOD)%MOD);
}