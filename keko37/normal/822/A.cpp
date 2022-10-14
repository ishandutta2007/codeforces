#include<iostream>

using namespace std;

typedef long long llint;

llint a, b, x, y, sol=1;

int main () {
	cin >> a >> b;
	int x=min(a, b);
	for (int i=1; i<=x; i++) {
		sol*=i;
	}
	cout << sol;
	return 0;
}