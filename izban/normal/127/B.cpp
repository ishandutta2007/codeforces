#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <algorithm>

using namespace std;

#define sqr(x) ((x)*(x))

int ans=0,n,a[200],x;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);	
	freopen("output.txt", "w", stdout);
#endif
	
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		a[x]++;
	}
	for (int i=1; i<=100; i++) {
		ans+=a[i]/4;
		a[i]=a[i]%4;
	}
	sort(a,a+101);
	for (int i=1; i<=101; i++) {
		for (int j=1; j<=101; j++) {
			if (i!=j && a[i]>1 && a[j]>1) {
				ans++;
				a[i]-=2; a[j]-=2;
			}
		}
	}
	cout << ans;
	return 0;
}