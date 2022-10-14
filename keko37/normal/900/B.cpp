#include<iostream>

using namespace std;

int a, b, c;

int main () {
	cin >> a >> b >> c;
	for (int i=0; i<1000000; i++) {
		a*=10;
		if (a/b==c) {
			cout << i+1;
			return 0;
		}
		a%=b;
	}
	cout << -1;
	return 0;
}