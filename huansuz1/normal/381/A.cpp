#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,c,d,x,y;
int a[1236];
 
int main(){
	cin>>n;
	x=0; y=n-1;
	for (int i=0; i<n; i++)
		cin>>a[i];
	for (int i=0; i<n; i++){
		if (i%2==0) {
			if (a[x]>a[y]) { c+=a[x]; x++; } else { c+=a[y]; y--; }
		} else 
			if (a[x]>a[y]) { d+=a[x]; x++; } else { d+=a[y]; y--; }
	
	   	}
	cout<<c<<" "<<d;
	return 0;
}