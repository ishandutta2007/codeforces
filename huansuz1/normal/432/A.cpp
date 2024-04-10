#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,m,k,z;
int a[123445];
 
int main(){
	cin>>n>>k;
	for (int i=1; i<=n; i++) 
		cin>>a[i];

	sort(a+1,a+n+1);
	for (int i=3; i<=n; i+=3) 
		if ((5-a[i])>=k)  m++;  else break;
	
	cout<<m;
	
	

     


	return 0;
}