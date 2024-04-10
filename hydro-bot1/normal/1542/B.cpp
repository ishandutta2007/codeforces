// Hydro submission #6257a218ac286d0a56ba99e9@1649910297012
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long t,a,b,n,f,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b;
		if(a==1)
		printf(n%b==1||n==1||b==1?"Yes\n":"No\n");
		else
		{
    		f=0;
    		for(i=1;i<=n;i*=a)
    		if(i%b==n%b) f=1;
    		printf(f?"Yes\n":"No\n");
		}
	}
	return 0;
}