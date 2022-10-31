#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int a[123456],n,z,zz ;

int main(){
	cin>>n;
	for (int i=0; i<n; i++)
		cin>>a[i];
	for  (int i=0; i<n; i++){
		if (a[i]==i) z++; else 
		if (a[i]!=i && a[a[i]]==i) zz++;
	}
	if (z==n) cout<<n; else 
	if (zz!=0) cout<<z+2; else 
	cout<<z+1;
	
	
	return 0;

}