#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

long long n,m,a[123456],b[123456],c[123456],ma=-1234567899;

int main(){
	cin>>n>>m;
	for (int i=0; i<n;  i++) {
		cin>>a[i]>>b[i];
		if (b[i]>m) c[i]=(a[i]-(b[i]-m)); else 
	c[i]=a[i];
		}
	
	 for (int i=0; i<n; i++)
	 	if (c[i]>ma)  ma=c[i];
	cout<<ma;
	
	return 0;
}