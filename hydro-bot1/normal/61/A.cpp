// Hydro submission #6247fb6d0bc575b66aa58b45@1648884589866
#include<bits/stdc++.h>
using namespace std;
string r,s;
int main()
{
    cin>>r>>s;int a,b,c,i;
    for(i=0;i<r.size();i++)
    {
    	a=r[i]-48,b=s[i]-48;
    	c=a^b;cout<<c;
	}
    return 0;
}