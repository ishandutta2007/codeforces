#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

long long n, k, c=1;

int main() {
	cin >> n >> k;
	while (k % 2 == 0) {
		k /= 2;
		c++;
	}
	cout << c;
}