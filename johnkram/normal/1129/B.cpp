#include<bits/stdc++.h>
using namespace std;
#define ll long long
int m,n=2000,i;
int main()
{
	cin>>m;
	cout<<n<<endl<<-1;
	m+=n;
	n--;
	for(i=1;i<=n;i++)cout<<' '<<(ll)i*m/n-(ll)(i-1)*m/n;
	return 0;
}