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
	cin>>n>>m;
	for (int i=0; i<n; i++)
		cin>>a[i];
	sort(a,a+n);
	for (int i=0; i<n; i++){
	s+=a[i]*m;
	if (m>1) m--;	
	}
	cout<<s;

	return 0;
}