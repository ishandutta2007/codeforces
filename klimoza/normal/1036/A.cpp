#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {
	long long int n, k;
	cin >> n >> k;
	if (k % n == 0) {
		cout << k / n << "\n";
	}
	else {
		cout << k / n + 1 << "\n";
	}
	//system("pause");
	return 0;
}