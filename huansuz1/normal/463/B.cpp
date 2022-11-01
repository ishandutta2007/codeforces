#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int n,e,d,p;
int a[123456];
 
int main(){
	cin>>n;
	for (int i=1; i<=n; i++) {
		cin>>a[i];           
		p=i-1;
		if (a[p]<a[i] && (e+a[p])<a[i]) {d+=a[i]-a[p]-e; e=0;} else 
			if (a[p]<a[i] && (e+a[p])>=a[i]) e-=a[i]-a[p]; else 
				if (a[p]>=a[i]) e+=a[p]-a[i];
		
	}
	cout<<d;

	return 0;
}