#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

map<int,int> st,ss,tt;
map<int,int> :: iterator it;
int n, x,xx,yy,y,z, m,a[345678],b[345678],c[234567];
char ch;

int main() {
    cin>>n;  
    x=1;
    for (int i = 1; i <= n; i++)
    {
     	cin>>a[i]>>b[i];
     	tt[a[i]]++;
     	tt[b[i]]++;

     	ss[a[i]]=b[i]; st[b[i]]=a[i];
     	if  (b[i]==0)  c[n-1]=a[i];

    }
    	
    	z=0;
    	    for (int i=1; i<=n; i++) {
    	    	z+=2;            
    	    	c[z]=ss[c[z-2]];
    	    	ss[c[z-2]]=-1;
    	    	if (z>n) break;
    	    	}
    	    

    	for (int i=1; i<=n; i++)
    		if (tt[a[i]]==1) {x=a[i];  c[1]=a[i]; }  
   
        z=1;
    	    for (int i=1; i<=n; i++) {
    	    	c[z+2]=ss[c[z]];
    	    	z+=2;
    	    	if (z>n) break;
    	    	
    	    	}
    	
   
   
   for (int i=1; i<=n; i++)
    	    	cout<<c[i]<<" ";

    

	return 0;
}