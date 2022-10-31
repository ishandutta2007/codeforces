#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

int n,k,z,a[1234],x,y,b[1234],s;

int main(){

	cin >> n ;
	for (int i=0; i<n; i++) {
		cin>>a[i];
		s+=a[i];
		b[i+1]=s;
	}
	cin>>x>>y;
	for (int i=1; i<=n; i++)
		if ((b[i]>=x && b[i]<=y) && ((s-b[i])>=x && (s-b[i])<=y)) {cout<<i+1; return 0;}
	cout<<0;

		
	return 0;
}