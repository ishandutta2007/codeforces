#include <iostream>
#include <algorithm>
using namespace std;
 
long long n,m,a[123456],s,z;

int main(){
     
	cin>>n;
	for (int i=0; i<n; i++)
		cin>>a[i];
	for (int i=0; i<n; i++)
		if (a[i]==-1 && s==0) z++; else
		if (a[i]==-1 && s>0) s--; else
		s+=a[i];
	cout<<z; 
	
		 
	return 0;
}