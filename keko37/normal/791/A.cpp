#include<iostream>

using namespace std;

typedef long long llint;

llint a, b, sol;

int main () {
	cin >> a >> b;
	while (a<=b) {
		a*=3;
		b*=2;
		sol++;
	}
	cout << sol;
	return 0;
}