#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <map>

using namespace std;

int a[1234];
int n,x,s,y;

int main() {
	
	cin>>n;
	for (int i=1; i<n; i++)
		cin>>a[i];
	cin>>x>>y;
	for (int i=x; i<y; i++)
		s+=a[i];
	cout<<s;
	return 0;
}