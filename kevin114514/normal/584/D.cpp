#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
void die(string S){puts(S.c_str());exit(0);}
bool isPrime(ll d)
{
	if(!d)
		return false;
	for(ll i=2;i<=sqrt(d);i++)
		if(d%i==0)
			return false;
	return true;
}
void Partitition(ll x,ll y)
{
	if(isPrime(x))
	{
		cout<<2<<endl;
		cout<<x<<" "<<y<<endl;
		exit(0);
	}
	for(ll i=2;i<=x;i++)
		if(isPrime(i)&&isPrime(x-i))
		{
			cout<<3<<endl;
			cout<<y<<" "<<i<<" "<<x-i<<endl;
			exit(0);
		}
}
int main()
{
	ll n;
	cin>>n;
	if(isPrime(n))
	{
		cout<<1<<endl;
		cout<<n<<endl;
		return 0;
	}
	for(ll i=n;i>=1;i--)
		if(isPrime(i))
			Partitition(n-i,i);
	puts("God damn it,there's no solution!");
	exit(0);
}