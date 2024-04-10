#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll mulmod(ll a,ll b,ll c) // Works for c<=1e12
{
        if(a<=2e9&&b<=2e9)
        {
                return (a*b)%c;
        }
        if(a>=c)
                a%=c;
        if(b>=c)
                b%=c;
        ll x = b/1000000,y=b%1000000;
        return ((a*y)+ (1000000*((a*x)%c)))%c;
}
ll power(ll a, ll n, ll mod)
{
    ll pwr = a%mod;
    ll result = 1;
 
    while (n)
    {
        if (n & 1)
            result = mulmod(result,pwr,mod);
        pwr = mulmod(pwr , pwr, mod);
        n >>= 1;
    }
    return result;
}
 
// n1 = 2^s * d with d odd by factoring powers of 2 from n1
bool witness(ll n, ll s, ll d, ll a)
{
    ll x = power(a, d, n);
    ll y;
 
    while (s) {
        y = mulmod(x,x,n);
        if (y == 1 && x != 1 && x != n-1)
            return false;
        x = y;
        --s;
    }
    if (y != 1)
        return false;
    return true;
}
 
bool is_prime(ll n) // Gives correct values for all n < 3e12
{     
    if (((!(n & 1)) && n != 2 ) || (n < 2) || (n % 3 == 0 && n != 3))
        return false;
    if (n <= 3)
        return true;
 
    ll d = n / 2;
    ll s = 1;
    while (!(d & 1)) {
        d /= 2;
        ++s;
    }
 
    if (n < 1373653)
        return witness(n, s, d, 2) && witness(n, s, d, 3);
    if (n < 9080191)
        return witness(n, s, d, 31) && witness(n, s, d, 73);
    if (n < 4759123141)
        return witness(n, s, d, 2) && witness(n, s, d, 7) && witness(n, s, d, 61);
    
  return (witness(n, s, d, 2) && witness(n, s, d, 13) && witness(n, s, d, 23) && witness(n, s, d, 1662803));
}

#define LL "%I64d"

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		scanf(LL,&n);
		if(n == 2){
			cout<<"1/6\n";
			continue;
		}
		ll x = n,y = n+1;
		while(!is_prime(x))
			x--;
		while(!is_prime(y))
			y++;
		ll num = x*y-2*y+2*n-2*x+2;
		ll den  = 2*x*y;
		ll g= __gcd(num,den);
		num/=g;
		den/=g;
		cout<<num<<"/"<<den<<"\n";
	}	
}