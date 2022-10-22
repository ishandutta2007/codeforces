#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
int main()
{
	cin>>n>>m;
	if(n>=m-1)cout<<(m-1>>1)<<endl;
	else if((n<<1)-1<m)cout<<0<<endl;
	else cout<<n-(m>>1)<<endl;
	return 0;
}