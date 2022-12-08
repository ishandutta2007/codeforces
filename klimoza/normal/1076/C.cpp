#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long int ll;


int main() {
	cout.precision(15);
	int t;
	double d;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> d;
		if (d < 4 && d > 0) {
			cout << "N\n";
			continue;
		}
		double a1 = (d - sqrt(d * d - 4 * d)) / 2;
		double b1 = d - a1;
		double a2 = (d + sqrt(d * d - 4 * d)) / 2;
		double b2 = d - a2;
		if (a1 >= 0 && b1 >= 0) {
			cout << "Y " << a1 << " " << b1 << "\n";
		}
		else if (a2 >= 0 && b2 >= 0) {
			cout << "Y " << a2 << " " << b2 << "\n";
		}
		else {
			cout << "N\n";
		}
	}
	//system("pause");  
	return 0;
}