#include<iostream>

using namespace std;

int n, x, a, b;

int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		if (i==0) {
			a=b=x;
		} else {
			a=min(a, x);
			b=max(b, x);
		}
	}
	cout << (a+b)/2;
	return 0;
}