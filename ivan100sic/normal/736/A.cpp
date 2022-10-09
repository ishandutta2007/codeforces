#include <iostream>
#include <string>
using namespace std;

int main() {
	long long n, a=0, b=0;
	int c = 0;
	cin >> n;
	
	while (b < n) {
		long long ab = a+b+1;
		a = b;
		b = ab;
		c++;
	}

	cout << c-1 << '\n';
}