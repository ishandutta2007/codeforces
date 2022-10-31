#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>

using namespace std;

long long n, x, y, m, k , z=1;

int main() {
	cin>>n>>k;
	x=1; y=k+1; z=k+2;
	for (int i=1; i<=n; i++){
		if (i%2==1 && i<=k+1) {cout<<x<<" "; x++;}else 
		if (i%2==0 && i<=k+1) {cout<<y<<" "; y--;}else	
		if (i>k+1) {cout<<z<<" "; z++; }
	}




    return 0;
}