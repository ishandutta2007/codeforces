#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
#include<set>
#include<map>
using std::cin;using std::cerr;
using std::max;using std::min;
#define mod 1000000007
#define ll long long
#define db double
#define dbg1(x) cerr<<#x<<"="<<(x)<<" "
#define dbg2(x) cerr<<#x<<"="<<(x)<<"\n"
int T,ans;ll n,m;
int cal(int x) {x-=x<mod?0:mod;return x;}
ll gcd(ll x,ll y) {return y?gcd(y,x%y):x;}
int main()
{
	for(scanf("%d",&T);T--;ans=0)
	{
		scanf("%lld",&n);
		ll mul=1;
		for(int i=2,val;mul<=n;mul=mul*i/gcd(mul,i),i++)
		{
			m=n/mul,val=i/gcd(mul,i);
			ans=(ans+(m-m/val)%mod*i)%mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}