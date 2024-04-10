#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[n];
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		if(a[i] >= 0)
			a[i] = -a[i] - 1;
	}
	if(n % 2 == 1) {
		int mn = -1, mxi;
		for(int i = 0; i < n; ++i)
			if(mn > a[i]) {
				mn = a[i];
				mxi = i;
			}
		if(mn == -1) 
			a[0] = 0;
		else a[mxi] = -a[mxi] - 1;
	}
	for(int i = 0; i < n; ++i)
		cout << a[i] << " ";

}