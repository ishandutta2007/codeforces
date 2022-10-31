#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

long long n,a[123456],b[123456],z;
long long s;

int main(){
	cin>>n;
	for (int i=0; i<n; i++)
		cin>>a[i];
	sort(a,a+n);
	
	
	for (int i=n-1; i>=0; i--)
		if (a[i]-a[i-1]<=1  && i-1>=0){ b[z]=a[i-1]; z++;i--;}   
	
		
	for (int i=0; i<z; i++)
		if (i+1<z)	 {s+=(b[i]*b[i+1]);  i++;}
	
	cout<<s;
		

	return 0;
}