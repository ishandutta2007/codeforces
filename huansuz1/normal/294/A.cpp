#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string>
#include <map>

using namespace std;

int a[1234],x[1234],y[1234];
int n,m;

int main() {
	
	cin>>n;
	for (int i=1; i<=n; i++)
		cin>>a[i];
	cin>>m;
	for (int i=1; i<=m; i++) 
		cin>>x[i]>>y[i];

	for (int i=1; i<=m; i++) {
		a[x[i]-1]+=y[i]-1;
		a[x[i]+1]+=a[x[i]]-y[i];
		a[x[i]]=0;
	}

	for (int i=1; i<=n; i++)
		cout<<a[i]<<endl;

	return 0;
}