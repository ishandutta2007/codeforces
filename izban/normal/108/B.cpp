#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>
using namespace std;

#define sqr(x) ((x)*(x))
int a[200000];
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
#endif
	int n,m,k=0;
	cin >> n;
	for (int i=0; i<n; i++) cin >>a[i];
	sort(a,a+n);
	for (int i=n-1; i>=0; i--) {
		if (a[i]>a[i-1]) {
			k=i-1;
			break;
		}
	}
	bool f=false;
	int l=0,r=0;
	for (int i=1; i<n; i++) {
		if (a[i]!=a[i-1]) {
			f=(a[i]/a[l]<2);
			if (f) break;
			l=i;
		}
	}
	if (f) cout << "YES";
	else cout << "NO";
	return 0;
}