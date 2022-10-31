#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <map>

using namespace std;

long long a[100009],n,m,s,z,p,k;
int main() {
	cin>>n>>m;
	while (p!=1){
		z++;
		if (z>m || m==0) {k=m; p=1; break;} else 
			m-=z;
		if (z==n) z=0;
	
	}
	cout<<k;
	
	return 0;
}