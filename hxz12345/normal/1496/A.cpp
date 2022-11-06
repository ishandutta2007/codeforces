#include<bits/stdc++.h>
using namespace std;
char c[10000];
int n,m,T,i,ans,j;
int main()
{
	cin>>T;
	while (T)
	    {
	    	cin>>n>>m;
	    	for (i=1;i<=n;i++) cin>>c[i];
	    	if (m==0) 
	    	   {
	    	   	cout<<"YES"<<endl;
			   }
			else
			  		{
			  			ans=0;
	    	i=1;j=n;
	    	while (j-i-1>0)
	    	     {
	    	     	if (c[i]==c[j])
	    	     	    {
	    	     	    i++;j--;ans++;	
						 }
					else break;
				 }
			if (ans>=m) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
				}
	    	T--;
		}
	return 0;
}