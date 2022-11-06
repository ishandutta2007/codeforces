#include<bits/stdc++.h>
using namespace std;
int T,n,i,e[3][100000],x;
int main()
{
	cin>>T;
	for (;T;T--)
	    {
	    	cin>>n;
	    	e[1][0]=0;e[0][0]=0;
	    	for (i=1;i<=n;i++) 
	    	    {
	    	    	cin>>x;
	    	    	e[x % 2][0]++;
	    	    	e[x % 2][e[x % 2][0]]=x;
				}
			for (i=1;i<=e[0][0];i++)
			    cout<<e[0][i]<<" ";
			for (i=1;i<=e[1][0];i++)cout<<e[1][i]<<" ";
			cout<<endl;
		}
}