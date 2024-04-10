#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,m,k,z=1,zz;
long long  a[12345];
 
int main(){
	cin>>n>>m;
	for (int i=0; i<n; i++)
		cin>>a[i];

	while (z!=0 || z!=1){	
	z=0;	      
	for (int i=0; i<n; i++) {
		if (a[i]>0) { a[i]-=m; k=i; z++; }
		}
          

	if (z==0 ) break;		
	}
	cout<<k+1;
		

	
	
	
	return 0;
}