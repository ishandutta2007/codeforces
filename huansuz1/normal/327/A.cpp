#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,a[1234],b[1234],ma;

int main(){
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i];
		b[i]=a[i];
		}
	for (int i=0; i<n; i++) {

		for (int j=i; j<n; j++){
			b[j]=1-b[j];
		int s=0;
		for (int jj=0; jj<n; jj++)  
			s+=b[jj];
		
		if (s>ma) ma=s;  
		
		}
		for (int j=0; j<n; j++)
			b[j]=a[j];
	}
	cout<<ma;

	
	return 0;
}