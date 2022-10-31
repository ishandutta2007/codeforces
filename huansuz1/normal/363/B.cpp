#include <algorithm>
#include <iostream>
#include <string>
#include <map>

 
 
using namespace std;
 
int n, a[1543211],s,mi=1000000000,k,z,x;
 
int main()
{
 
    cin>>n>>k;
    for (int i=1; i<=n; i++)  {
    	cin>>a[i];
    	s+=a[i];
    	z++;
    	if (z==k+1) { z--; s-=a[i-k];}   
    	if (z==k && s<mi) {mi=s;x=i-k+1;}
    }
    cout<<x;
    	
    return 0;
}