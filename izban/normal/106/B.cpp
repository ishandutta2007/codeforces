#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

#define sqr(x) ((x)*(x))
int a[100],b[100],c[100],d[100];
bool f[100];
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
#endif
	int n,m,i,j,k=0,ans=2<<15;;
	cin >> n;
	for (i=0; i<n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			if (i!=j && a[i]<a[j] && b[i]<b[j] && c[i]<c[j]) f[i]=true;
		}
	}
	for (i=0; i<n; i++) {
		if (!f[i] && ans>d[i]) {
			k=i;
			ans=d[i];
		}
	}
	cout << k+1;
	return 0;
}