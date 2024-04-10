#include <iostream>
#include <algorithm>
using namespace std;
 
long long n,m,a[1234],z,p;

int main(){
     
	cin>>n;
	for (int i=0; i<12; i++)
		cin>>a[i];
	sort(a,a+12);

	if (n==0) cout<<0; else {
	for (int i=11; i>=0; i--){
		m+=a[i];
		z++;
		if (m>=n) {cout<<z;p=1; break;}	
	}
	  if (p==0)  cout<<-1;                      } 
	
		 
	return 0;
}