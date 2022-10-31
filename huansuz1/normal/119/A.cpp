#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;
	int n,m,k,x,y,z,zz;

int main(){
	cin >> n >> m >> k;

	while ( n != 0) {
		for (int i=1; i<=k; i++)
		if (n % i == 0 && k % i == 0)  x=i;
		k-=x;  
		if (k<0) {z=0; zz=1; break; } else 
		if (k==0){z=1; zz=0; break;}
		for (int i=1; i<=k; i++)
			if (m % i == 0 && k % i == 0)  y=i;
				k-=y; 
		if (k<0) {zz=0; z=1; break; } else 
		if (k==0){zz=1; z=0; break;}
	}
	if (z>zz) cout<<0; else cout<<1;
	
       }