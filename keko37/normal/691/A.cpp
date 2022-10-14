#include<iostream>

using namespace std;

int n, x, cnt;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		cnt+=x;
	}
	if (n==1) {
		if (x==1) cout << "YES"; else cout << "NO";
	} else {
		if (cnt==n-1) cout << "YES"; else cout << "NO";
	}
	return 0;
}