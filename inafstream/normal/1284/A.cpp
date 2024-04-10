#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
#define per(i,n) for ((i)=n;(i)>=(1);(i)--)
using namespace std;

int n,m,q,x;
string a[25],b[25];

int main()
{
	int i,j;
	
	cin>>n;cin>>m;
	rep(i,n) cin>>a[i-1];
	rep(i,m) cin>>b[i-1];
	
	cin>>q;
	while (q--)
	{
		cin>>x;
		cout<<a[(x-1)%n]<<b[(x-1)%m]<<endl;
	}
	
	return 0;
}