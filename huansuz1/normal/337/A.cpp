#include <iostream>
#include <algorithm>
using namespace std;
 
int  n,a[1234],k,mi=12345;

int main(){
     
	cin>>k>>n;
	for (int i=0; i<n; i++)
		cin>>a[i];
	sort(a,a+n);
	for (int i=0; i<=n-k; i++)
	if ((a[i+k-1]-a[i])<mi) mi=(a[i+k-1]-a[i]);
	cout<<mi;

     return 0;
}