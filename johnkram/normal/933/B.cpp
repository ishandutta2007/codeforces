#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,x,i,m,a[105],N;
int main()
{
	cin>>n>>m;
	for(;n;n=x)
	{
		if(n>0)x=-(n/m);
		else x=(m-1-n)/m;
		a[++N]=n+x*m;
	}
	cout<<N<<endl;
	for(i=1;i<=N;i++)cout<<a[i]<<' ';
	return 0;
}