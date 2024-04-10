#include<iostream>

using namespace std;

int n, a, x;

int main () {
	cin >> n >> a;
	x=n-a;
	for (int i=1; i<n; i++) {
		cin >> a;
		if (i%2==0 && (a+x)%n!=i || i%2==1 && (a-x+n)%n!=i) {
			cout << "no";
			return 0;
		}
	}
	cout << "yes";
	return 0;
}