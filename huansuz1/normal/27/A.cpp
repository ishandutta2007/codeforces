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
int n,a[12345],m;
int main() {
	cin>>n;
	for (int i=0; i<n; i++){
		cin>>m;
		a[m]=1;
	}
	n=0;
	for (int i=1; i<=1000000; i++)
		if (a[i]!=1) {n=i; break;}
	cout<<n;
	return 0;
}