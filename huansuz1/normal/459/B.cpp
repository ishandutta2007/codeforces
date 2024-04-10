#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long n , a[223456] , zz , z , s;

int main(){
	long long mi = 1234567891, ma = 0; 
    cin >> n ;
    for (int i = 1; i <= n; i++ )  {
		cin >> a[i];	
		if (a[i]>ma) ma=a[i];
	    if (a[i]<mi) mi=a[i];
	}
	for (int i = 1; i <= n; i++ ) {
		if (a[i] == ma) z++;
		if (a[i] == mi) zz++; 
	}
	if (ma != mi ) cout << ma-mi << " " << z*zz;  
		else {
	    	for (int i=1; i<=n-1; i++)
	        	s+=i;
		cout << 0 << " " << s;
		} 


	return 0;
}