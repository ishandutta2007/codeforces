#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


long long gcd(long long int x, long long y) {
	if (x == 0) return y;
	if (y == 0) return x;
	return gcd(y, x % y);
}



int main() {
	long long int a, b, x, y;
	cin >> a >> b >> x >> y;
	long long int t = gcd(x, y);
	x /= t;
	y /= t;
	cout << min(a / x, b / y) << "\n";
	//system("pause");
	return 0;
}