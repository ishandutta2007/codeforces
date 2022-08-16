#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))


const ll mod = 1e9+7;
ll N = 110;
const ll N1 = 110;
void mul(ll A[N1][N1],ll B[N1][N1])
{
	ll C[N1][N1];
	rep(i,0,N)
	rep(j,0,N)
	{
		ll x = 0;
		rep(k,0,N)
		x = (x+A[i][k]*1ll*B[k][j])%mod;
		C[i][j] = (ll)x;
	}
	rep(i,0,N)
	rep(j,0,N)
	A[i][j] = C[i][j];
}
void modpow(ll A[N1][N1], ll n)
{
	ll I[N1][N1];
	memset(I,0,sizeof I);
	rep(i,0,N)
	I[i][i] = 1;
	while(n)
	{
		if(n&1)
			mul(I,A);
		mul(A,A);
		n>>=1;
	}
	rep(i,0,N)
	rep(j,0,N)
	A[i][j] = I[i][j];
}
ll a[N1];

ll cnt1(ll x)
{
	ll ret = 0;
	while(x)
	{
		if(x&1)
			ret++;
		x>>=1;
	}
	return ret;
}
int main()
{
    ll n,k;
    cin>>n>>k;
    rep(i,0,n)
    cin>>a[i];
 	ll B[N1][N1];
 	memset(B,0,sizeof B);
    rep(i,0,n)
    rep(j,0,n)
    if(cnt1(a[i]^a[j])%3 == 0)
        B[i][j] = 1;
    if(k == 1)
    {
        cout<<n;
        return 0;
    }
    modpow(B,k - 1);
    ll ans = 0;
    rep(i,0,n)
    rep(j,0,n)
    ans=(ans+B[i][j])%mod;
    cout<<ans;
}