#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <map>

using namespace std;

int a[100009],n,m,s,z,p;
int main() {
	cin>>n>>m;
	for (int i=1; i<=n; i++)
	a[i]=i;
	
	for (int i=n; i>=n-m+1; i--)
		cout<<a[i]<<" ";
	for (int i=1; i<=n-m; i++)
		cout<<a[i]<<" ";
	return 0;
}