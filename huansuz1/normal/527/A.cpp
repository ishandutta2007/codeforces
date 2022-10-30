#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>
 
using namespace std;

long long n,m,z;
int main()
{
cin>>n>>m;
if (m==1) {cout<<n; exit(0);}

while(n!=0 && m!=0){
	if (n>m) {z+=n/m; n%=m;}
	else {z+=m/n; m%=n;}
}
cout<<z;
   return 0;
}