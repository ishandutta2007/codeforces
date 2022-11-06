#include<bits/stdc++.h>
using namespace std;
long long sum,T,n,i,x,a[1010000];
int main()
{
	cin>>T;
	for (;T;T--)
	    {
	    	cin>>n;x=1000;
	    	for (i=1;i<=n;i++) cin>>a[i],x=min(x,a[i]);sum=0;
	    	for (i=1;i<=n;i++)
	    	    if (a[i]==x) sum++;
	        cout<<n-sum<<endl;
		}
	return 0;
}