#include <iostream>
#include <cmath>
using namespace std;

long long unsigned n, m, a;

int main() {
	cin >> n >> m >> a;
	cout << ((n+a-1) / a) * ((m+a-1)/a) << endl;
	return 0;
}