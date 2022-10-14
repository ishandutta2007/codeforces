#include<iostream>

using namespace std;

int n;

int main () {
	cin >> n;
	if (n%4==0) {
		cout << 0 << endl << n/2 << " ";
	} else if (n%4==1) {
		cout << 1 << endl << n/2 << " ";
	} else if (n%4==2) {
		cout << 1 << endl << n/2 << " 1 ";
	} else {
		cout << 0 << endl << n/2 << " 3 ";
	}
	for (int i=1; i<=n/4; i++) {
		cout << i+n%4 << " " << n-i+1 << " ";
	}
	return 0;
}