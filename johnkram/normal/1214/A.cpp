#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define P 1000000007
#define MAXN 1000005
int Pow(int x,int y)
{
	int s=1;
	for(;y;y>>=1,x=(ll)x*x%P)if(y&1)s=(ll)s*x%P;
	return s;
}
int gcd(int x,int y)
{
	if(!y)return x;
	return gcd(y,x%y);
}
int n,a,b,i;
bool f[MAXN];
int main()
{
	cin>>n>>a>>b;
	b*=5;
	f[0]=1;
	for(i=0;i+a<MAXN;i++)if(f[i])f[i+a]=1;
	for(i=0;i+b<MAXN;i++)if(f[i])f[i+b]=1;
	if(n<MAXN)
	{
		for(i=n;~i;i--)if(f[i])break;
		cout<<n-i<<endl;
		return 0;
	}
	i=gcd(a,b);
	cout<<n%i<<endl;
	return 0;
}