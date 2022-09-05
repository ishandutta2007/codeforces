#include<bits/stdc++.h>
using namespace std;

typedef long long s64;

int main()
{
	s64 n,m,k;
	cin>>n>>m>>k;
	++k;
	if(k<=n)cout<<k<<" "<<1; else
	{
		k-=n;
		s64 d=(k-1)/(m-1),x=(k-1)%(m-1);
		cout<<n-d<<" "<<(d%2?m-x:2+x);
	}
}