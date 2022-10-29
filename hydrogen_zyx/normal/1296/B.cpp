#include<iostream>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int sum = 0;
		while (n >= 10) {
			sum += n / 10 * 10;
			n = n % 10 + n / 10;
		}
		sum += n;
		cout << sum << endl;
	}
}