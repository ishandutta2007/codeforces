#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	if (n % 2 == 1) {
		cout << "9 " << n-9 << '\n';
	} else {
		cout << "8 " << n-8 << '\n';
	}	
}