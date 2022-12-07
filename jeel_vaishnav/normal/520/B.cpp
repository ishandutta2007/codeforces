#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,b;
	cin>>a>>b;
	int ans=0;
	while(b>a)
	{
		if(b%2==0)
		ans+=1;
		else
		ans+=2;
		b=(b+1)/2;
	}
		ans+=(a-b);
		cout<<ans;
}