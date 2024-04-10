#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <map>

using namespace std;

long long a[100009],n,m,s,z,p;
int main() {
	cin>>n;
	for (int i=0; i<n; i++) {
		cin>>a[i];
		s+=a[i];
	}
	
	for (int i=1; i<=5; i++)
		if ((s+i)%(n+1) !=1 ) z++;
	cout<<z;
	
	return 0;
}