#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const long long N = 1e5+10;
const long long p = 1e9+7;
long long n,m,a[N],b[N],inv[N];

int main()
{
	inv[1] = 1;
	for(long long i=2;i <= 100000;i++) inv[i] = (p-p/i)*inv[p%i]%p;
	cin>>n>>m;
	for(long long i=1;i <= n;i++) cin>>a[i];
	for(long long i=1;i <= n;i++) cin>>b[i];
	long long q = 0;
	for(long long i=1;i <= m;i++) q = (q+(m-i)*inv[m])%p;
	q = q*inv[m]%p;
	long long x = 1,ans = 0;
	for(long long i=1;i <= n;i++)
	{
		if(a[i] && b[i])
		{
			if(a[i] == b[i]) continue;
			if(a[i] > b[i]) ans = (ans+x)%p;
			break;
		}
		if(!a[i] && !b[i]) ans = (ans+q*x)%p;
		else if(a[i]) ans = (ans+x*(a[i]-1)%p*inv[m]%p)%p;
		else ans = (ans+x*(m-b[i])%p*inv[m]%p)%p;
		x = x*inv[m]%p;
	}
	cout<<ans<<endl;
	return 0;
}