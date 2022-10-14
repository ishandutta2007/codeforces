#include<iostream>
#include<algorithm>

using namespace std;

int n;
int l[1005];

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> l[i];
	}
	sort(l, l+n);
	if (n%2==0) {
		for (int i=0; i<n/2; i++) {
			cout << l[i] << " " << l[n-i-1] << " ";
		}
	} else {
		for (int i=0; i<=n/2; i++) {
			cout << l[i] << " ";
			if (i!=n/2) cout << l[n-i-1] << " ";
		}
	}
	return 0;
}