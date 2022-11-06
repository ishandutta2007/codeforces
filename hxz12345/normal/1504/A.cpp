#include<bits/stdc++.h>
using namespace std;
string s;
int T,i,l,r,len;
bool flag;
char a[500000];
int main()
{
	cin>>T;
	for (;T;T--)
	    {
	    	cin>>s;
	    	len=s.size();
	    	for (i=1;i<=len;i++) a[i]=s[i-1];
	    	flag=false;
	    	l=1;r=len;
	    	while ((l<=r))
	    	     {
	    	     	if (flag) break;
	    	     	if ((a[l]!='a'))
	    	     	    {
	    	     	    	flag=true;
	    	     	    	cout<<"YES"<<endl;
	    	     	    	for (i=1;i<=r;i++) cout<<a[i];
	    	     	    	cout<<"a";
	    	     	    	for (i=r+1;i<=len;i++) cout<<a[i];
	    	     	    	cout<<endl;
						 }
					else if ((a[r]!='a'))
					      {
					      	flag=true;
					      	cout<<"YES"<<endl;
					      	for (i=1;i<l;i++) cout<<a[i];
					      	cout<<"a";
					      	for (i=l;i<=len;i++) cout<<a[i];
					      	cout<<endl;
						  }
					l++;r--;
				 }
			if (flag==false) cout<<"NO"<<endl;
		}
	return 0;
}