#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int q,i,j,k;
 	cin>>q;
 	ll n,m;
 	while(q--)
 	{
 		cin>>n;
 		m=n;
 		i=0;
 		j=0;
 		k=0;
 		while(m%2==0)
 		{
 			i+=1;
 			m/=2;
		}
		while(m%3==0)
 		{
 			j+=1;
 			m/=3;
		}
		while(m%5==0)
 		{
 			k+=1;
 			m/=5;
		}
		if(m==1)cout<<i+2*j+3*k<<"\n";
		else cout<<-1<<"\n";
	}
	return 0;
}