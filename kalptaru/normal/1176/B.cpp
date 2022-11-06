#include <bits/stdc++.h>
#include <string>
#include <cmath>
typedef long long int ll;
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 	int t;
 	cin>>t;
 	while(t--)
 	{
 		int n,i=0,j=0,k=0,ans=0;
 		cin>>n;
 		ll a;
 		for(int l=0;l<n;l++)
		{
			cin>>a;
			if(a%3==0)i+=1;
			else if(a%3==1)j+=1;
			else k+=1;
		}
		ans+=i;
		if(j<k)
		{
			ans+=j;
			k-=j;
			k=k/3;
			ans+=k;
		}
		else
		{
			ans+=k;
			j-=k;
			j=j/3;
			ans+=j;
		}
		cout<<ans<<"\n";
	}
	return 0;
}