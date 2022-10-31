#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

long long x[1234567];
long long n , m , z=1,p;

int main(){

	cin >> n;
	x[0]=0; x[1]=1;
	while (x[z]<1000000000) {
		z++;
		x[z]=x[z-1]+x[z-2];
	}
	for (int i=0; i<=z; i++)
		if (x[i]==n) {p=i; break;}
	if (n==0) cout<<"0 0 0"; else 
	if (n==1) cout<<"0 0 1"; else 
	if (n==2) cout<<"0 1 1"; else 
		cout<<x[p-1]<<" "<<x[p-3]<<" "<<x[p-4];
	return 0;
}