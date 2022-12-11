#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <int,int> pii;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back

const int MAXK=100005,MOD=1000000009;

char op[MAXK];

int get_inv(int x)
{
	if (x==1)
		return 1;
	return (LL)(MOD-MOD/x)*get_inv(MOD%x)%MOD;
}

int quick_pow(int a,int x)
{
	int ret=1;
	while (x)
	{
		if (x&1) ret=(LL)ret*a%MOD;
		a=(LL)a*a%MOD;
		x>>=1;
	}
	return ret;
}

int main()
{
	int n,a,b,k;
	scanf("%d%d%d%d",&n,&a,&b,&k);
	scanf("%s",op);
	int sum=0;
	for (int i=0;i<k;i++)
	{
		sum=(sum+(LL)(op[i]=='+'?1:-1)*quick_pow(a,n-i)*quick_pow(b,i)%MOD+MOD)%MOD;
	}
	int q=(LL)get_inv(quick_pow(a,k))*quick_pow(b,k)%MOD,p=(n+1)/k;
	if (q==1)
		printf("%lld",(LL)sum*p%MOD);
	else
		printf("%lld",(LL)sum*(quick_pow(q,p)-1)%MOD*get_inv(q-1)%MOD);
	return 0;
}